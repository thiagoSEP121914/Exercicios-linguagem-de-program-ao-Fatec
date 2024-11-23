#include <stdio.h>
#include <stdlib.h>


/*
Escreva um programa que leia o peso de um
lutador. Em seguida informe a categoria a que
pertence o lutador, conforme a tabela ao lado
(note que a tabela foi criada para efeito deste
exercício e não condiz com qualquer categoria
de luta). A saída do programa deve exibir na tela
um texto no seguinte padrão:
Peso fornecido: 73.4
Saída exibida na tela: Este lutador pesa 73.4 kg e se enquadra na categoria Ligeiro
*/

int main() {
    int peso;

    printf("Digite o peso do lutador: ");
    scanf("%d", &peso);

    printf("O peso do lutador eh: ");
    if(peso >= 100)
        printf("PESADO!");
    else if(peso >= 93 && peso < 100)
        printf("MEIO PESADO!");
    else if(peso >= 86 && peso < 93)
        printf("MEDIO!");
    else if(peso >= 79 && peso < 86)
        printf("MEIO  MEDIO!");
    else if(peso >= 72 && peso < 79)
        printf("LIGEIRO!");
    else if(peso >= 65 && peso < 72)
        printf("LEVE!");

    else
        printf(" PENA!");

    getchar();
    return 0;
}
