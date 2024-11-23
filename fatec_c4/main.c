#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que leia dois dados
inteiros de entrada, calcule e exiba o resultado conforme a fórmula abaixo:
*/

int main() {

    int A,B,R;


    printf("Digite o primeiro numero: ");
    scanf("%d", &A);

    printf("Digite o segundo numero: ");
    scanf("%d", &B);

    R = (3 * A ) + (2 * B) / A + B;

    printf("O resultado eh: R");

    getchar();

    return 0;

}
