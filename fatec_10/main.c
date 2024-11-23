#include <stdio.h>
#include <stdlib.h>

/*
5. Escreva um programa que leia três números
reais e informe se eles constituem os lados de um triângulo. Em caso afirmativo, informe se o triângulo
é equilátero, isósceles ou escaleno. Para que três números formem um triângulo deve ocorrer que a
soma dos dois lados menores deve ser maior que o lado maior. Para resolver essa questão será preciso
usar os operadores and e or
*/

int main() {
    float A,B,C;

    printf("Digite o lado A: ");
    scanf("%f", &A);

    printf("Digite o lado B: ");
    scanf("%f", &B);

    printf("Digite o lado C: ");
    scanf("%f", &C);

    if(A + B > C || B + C > A || A + C > B){
        printf("EH UM TRIANGULO!: ");
        if(A == B && B == C)
            printf("EQUILATERO!");

        else if(A == B || B == C || A == C)
            printf("ISOCELES!");

        else if(A != B && B != C)
            printf("ESCALENO!");
    }else{
        printf("NAO EH UM TRIANGULO!");
    }

    getchar();

    return 0;
}
