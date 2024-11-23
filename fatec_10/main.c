#include <stdio.h>
#include <stdlib.h>

/*
5. Escreva um programa que leia tr�s n�meros
reais e informe se eles constituem os lados de um tri�ngulo. Em caso afirmativo, informe se o tri�ngulo
� equil�tero, is�sceles ou escaleno. Para que tr�s n�meros formem um tri�ngulo deve ocorrer que a
soma dos dois lados menores deve ser maior que o lado maior. Para resolver essa quest�o ser� preciso
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
