#include <stdio.h>
#include <stdlib.h>

int main() {
    int Min, Max, A;

    printf("Digite o valor de Min (deve ser no mínimo 1): ");
    scanf("%d", &Min);

    while (Min < 1) {
        printf("Min deve ser no mínimo 1. Digite novamente: ");
        scanf("%d", &Min);
    }

    printf("Digite o valor de Max (deve ser maior que Min): ");
    scanf("%d", &Max);

    while (Max <= Min) {
        printf("Max deve ser maior que Min. Digite novamente: ");
        scanf("%d", &Max);
    }

    printf("Digite o valor de A: ");
    scanf("%d", &A);

    int tamanho = (Max - Min) / A + 1;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Falha na alocacao de memoria\n");
        return 1;
    }

    int i, j = 0;
    for (i = Min; i <= Max; i++) {
        if (i % A == 0) {
            vetor[j] = i;
            j++;
        }
    }

    printf("Valores divisíveis por %d entre %d e %d:\n", A, Min, Max);
    for (i = 0; i < j; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}
