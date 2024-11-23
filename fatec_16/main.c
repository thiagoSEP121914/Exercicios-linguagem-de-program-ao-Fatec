#include <stdio.h>
#include <stdlib.h>

int* diVI(int min, int max, int a, int *tam) {
    int *ptr;

    if (min < 1 || max <= min) {
        printf("Valores inválidos para Min e Max.\n");
        *tam = 0;
        return NULL;
    }

    ptr = (int *)malloc((max - min) * sizeof(int));
    if (ptr == NULL) {
        printf("Erro na alocação de memória!\n");
        *tam = 0;
        return NULL;
    }

    *tam = 0;
    for (int i = min; i <= max; i++) {
        if (i % a == 0) {
            ptr[*tam] = i;
            (*tam)++;
        }
    }

    return ptr;
}

int main() {
    int min = 0, max = 0, a;
    int *divisivel;
    int tamanho;

    while (min < 1) {
        printf("Digite o valor mínimo: ");
        scanf("%d", &min);
    }

    do {
        printf("Digite o valor máximo: ");
        scanf("%d", &max);
    } while (max <= min);

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    divisivel = diVI(min, max, a, &tamanho);

    if (divisivel != NULL) {
        printf("Valores divisíveis por %d entre %d e %d:\n", a, min, max);
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", divisivel[i]);
        }
        printf("\n");
    } else {
        printf("Nenhum valor divisível por %d encontrado entre %d e %d.\n", a, min, max);
    }

    free(divisivel);

    return 0;
}
