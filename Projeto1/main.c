#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int codigo;
    char modo_controle;
    float quantidade_estoque;
    float preco_custo;
    float margem_lucro;
} Produto;

Produto* ler_produtos(const char* arquivo, int* num_produtos) {
    FILE* file = fopen(arquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int capacidade = 15;
    *num_produtos = 0;
    Produto* produtos = (Produto*)malloc(capacidade * sizeof(Produto));
    if (!produtos) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d;%c;%f;%f;%f;", &produtos[*num_produtos].codigo,
                  &produtos[*num_produtos].modo_controle,
                  &produtos[*num_produtos].quantidade_estoque,
                  &produtos[*num_produtos].preco_custo,
                  &produtos[*num_produtos].margem_lucro) == 5) {
        (*num_produtos)++;
        if (*num_produtos >= capacidade) {
            capacidade *= 2;
            produtos = (Produto*)realloc(produtos, capacidade * sizeof(Produto));
            if (!produtos) {
                perror("Erro ao realocar memória");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    return produtos;
}

void obter_dados_usuario(int* ano, int* mes, int* qtde_vendas_dia) {
    do {
        printf("Digite o ano (minimo 2016): ");
        scanf("%d", ano);
    } while (*ano < 2016);

    do {
        printf("Digite o mes (1-12): ");
        scanf("%d", mes);
    } while (*mes < 1 || *mes > 12);

    printf("Digite a quantidade diaria de vendas: ");
    scanf("%d", qtde_vendas_dia);
}

int dias_no_mes(int mes, int ano) {
    if (mes == 2) {
        return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
    }
    return (mes == 4 || mes == 6 || mes == 9 || mes == 11) ? 30 : 31;
}

float calcular_preco_venda(float preco_custo, float margem_lucro) {
    return preco_custo * (1 + margem_lucro / 100.0);
}

typedef struct {
    int dia;
    int mes;
    int ano;
    int codigo_produto;
    float quantidade_vendida;
    float preco_venda;
} Venda;

void gerar_vendas(Produto* produtos, int num_produtos, int ano, int mes, int qtde_vendas_dia, Venda* vendas, int* total_vendas) {
    int dias_mes = dias_no_mes(mes, ano);
    *total_vendas = 0;

    for (int dia = 1; dia <= dias_mes; dia++) {
        for (int i = 0; i < qtde_vendas_dia; i++) {
            int idx_produto = rand() % num_produtos;
            Produto* produto = &produtos[idx_produto];
            float preco_venda = calcular_preco_venda(produto->preco_custo, produto->margem_lucro);

            if (rand() % 100 < 35) {
                float variacao = ((rand() % 17) - 8) / 100.0;
                preco_venda *= (1 + variacao);
            }

            vendas[*total_vendas].dia = dia;
            vendas[*total_vendas].mes = mes;
            vendas[*total_vendas].ano = ano;
            vendas[*total_vendas].codigo_produto = produto->codigo;
            vendas[*total_vendas].quantidade_vendida = (produto->modo_controle == 'P') ? (rand() % 1000) / 1000.0 : (rand() % 10) + 1;
            vendas[*total_vendas].preco_venda = preco_venda;

            (*total_vendas)++;
        }
    }
}
void escrever_vendas(const char* arquivo, Venda* vendas, int total_vendas) {
    FILE* file = fopen(arquivo, "w");
    if (!file) {
        perror("Erro ao abrir o arquivo de saída");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < total_vendas; i++) {
        fprintf(file, "%d;%02d;%02d;%05d;%.3f;%.2f;\n",
                vendas[i].ano, vendas[i].mes, vendas[i].dia,
                vendas[i].codigo_produto, vendas[i].quantidade_vendida,
                vendas[i].preco_venda);
    }

    fclose(file);
}

Venda* ler_vendas(const char* arquivo, int* total_vendas) {
    FILE* file = fopen(arquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo de vendas");
        exit(EXIT_FAILURE);
    }

    int capacidade = 15;
    *total_vendas = 0;
    Venda* vendas = (Venda*)malloc(capacidade * sizeof(Venda));
    if (!vendas) {
        perror("Erro ao alocar memória para vendas");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d;%d;%d;%d;%f;%f;", &vendas[*total_vendas].ano,
                  &vendas[*total_vendas].mes,
                  &vendas[*total_vendas].dia,
                  &vendas[*total_vendas].codigo_produto,
                  &vendas[*total_vendas].quantidade_vendida,
                  &vendas[*total_vendas].preco_venda) == 6) {
        (*total_vendas)++;
        if (*total_vendas >= capacidade) {
            capacidade *= 2;
            vendas = (Venda*)realloc(vendas, capacidade * sizeof(Venda));
            if (!vendas) {
                perror("Erro ao realocar memória para vendas");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    return vendas;
}

void mostrar_vendas_na_tela(const char* arquivo) {
    FILE* file = fopen(arquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo de vendas");
        exit(EXIT_FAILURE);
    }

    printf("Conteúdo do arquivo de vendas '%s':\n", arquivo);

    char linha[100];  // Tamanho arbitrário para cada linha
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }

    fclose(file);
}

int main() {
    FILE * ARQUIVO;
    srand(time(NULL));

    Produto* produtos;
    int num_produtos;
    produtos = ler_produtos("PRODUTOS.TXT", &num_produtos);

    int ano, mes, qtde_vendas_dia;
    obter_dados_usuario(&ano, &mes, &qtde_vendas_dia);

    int dias_mes = dias_no_mes(mes, ano);
    int total_vendas_estimada = qtde_vendas_dia * dias_mes;
    Venda* vendas = (Venda*)malloc(total_vendas_estimada * sizeof(Venda));
    if (!vendas) {
        perror("Erro ao alocar memória para vendas");
        exit(EXIT_FAILURE);
    }

    int total_vendas;
    gerar_vendas(produtos, num_produtos, ano, mes, qtde_vendas_dia, vendas, &total_vendas);

    escrever_vendas("VENDAS.TXT", vendas, total_vendas);
    mostrar_vendas_na_tela("VENDAS.TXT");

    free(produtos);
    free(vendas);

    return 0;
}
