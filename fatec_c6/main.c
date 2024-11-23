#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que leia um número
inteiro e informe se ele é par ou ímpar.

*/

int main() {
    int num;
    char par_impar[50];

    printf("Digite um numero: ");
    scanf("%d", &num);

    par_impar = (num % 2 == 0) ? "PAR": "IMPAR";

    printf("O numero digitado eh: %s", par_impar);

    getchar();
    return 0;
}
