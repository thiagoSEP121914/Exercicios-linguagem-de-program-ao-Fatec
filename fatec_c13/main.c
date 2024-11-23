#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher(int *vetor, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 101;
    }
}

void exibirVetor(int *vetor, int tamanho) {
    int i;
    printf("Vetor gerado:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int * encontrarIndices(int *vetor, int tamanho, int valor, int *numIndices) {
    int i;
    int *indices = (int *)malloc(tamanho * sizeof(int));
    *numIndices = 0;

    if (indices == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            indices[*numIndices] = i;
            (*numIndices)++;
        }
    }

    return indices;
}

int main() {
    int *vetor;
    int tamanho, valor, i, numIndices;
    int *indices;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Falha na alocacao de memoria\n");
        return 1;
    }

    srand(time(NULL));
    preencher(vetor, tamanho);
    exibirVetor(vetor, tamanho);

    printf("Digite um valor para verificar se esta presente no vetor: ");
    scanf("%d", &valor);

    indices = encontrarIndices(vetor, tamanho, valor, &numIndices);

    if (numIndices > 0) {
        printf("O valor %d foi encontrado nass posicoes: ", valor);
        for (i = 0; i < numIndices; i++) {
            printf(" %d", indices[i]+1);
        }
        printf("\n");
    } else {
        printf("O valor %d nao foi encontrado no vetor.\n", valor);
    }

    free(vetor);
    free(indices);
    return 0;
}

