#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0;
    do{
        printf("Digite um numero: ");
        scanf("%d", &x);
        if(x > 0)
            printf("POSITIVO!");
        else if(x == 0)
            printf("Eh ZERO!");
        else
            printf("NEGATIVO!");

        printf("\n");

    }while(x != 0);
    printf("PROGRAMA ENCERRADO!");

    getchar();
    return 0;
}
