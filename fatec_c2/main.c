#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que leia quatro números
inteiros A, B, C e D. Calcule e mostre na tela a soma e a média desses quatro números. Fique atento com
o tipo da variável a ser usada para cálculo da média, pois o resultado pode ser um número real.
*/


int main() {
    int A,B,C,D,soma;
    float media;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);
    printf("Digite o valor de C: ");
    scanf("%d", &C);
    printf("Digite o valor de D: ");
    scanf("%d", &D);

    soma = A+B+C+D;

    printf("A soma dos numeros eh: %d\n", soma);

    media = soma/4;
    printf("A Media artimetica eh: %2.f", media);

    getchar();

    return 0;
}
