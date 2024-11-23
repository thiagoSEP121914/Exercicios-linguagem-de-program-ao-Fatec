#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 1,maior = 0,menor = 999;
    int cont = 0, acumulador = 0;

    while(num > 0){

        printf("Digite um numero: ");
        scanf("%d", &num);
        if(num > maior){
            maior = num;
        }

        if(num < menor && num != 0){
            menor = num;
        }
        acumulador+= num;
        cont++;
    }

    cont = cont - 1;
    int media = acumulador/cont;

    printf("O maior valor digitado eh: %d\n", maior);
    printf("O menor valor digitado eh: %d\n", menor);
    printf("A quantidade de digitada eh: %d\n", cont);
    printf("A soma eh : %d\n", acumulador);
    printf("A media eh: %d\n", media);

    getchar();
    return 0;
}
