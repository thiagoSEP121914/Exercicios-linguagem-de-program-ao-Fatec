#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que leia um n�mero
inteiro e informe se ele � positivo, zero ou negativo.
*/

int main() {
    int num;


    printf("Digite um numero: ");
    scanf("%d", &num);

    if(num > 0)
        printf("Ele eh positivo!");

    else if(num == 0)
        printf("Ele eh zero!");

    else
        printf("Ele eh negativo!");

    getchar();

    return 0;
}
