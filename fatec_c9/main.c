#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
4. Escreva um programa que leia três números
reais A, B e C que são os coeficientes de uma equação do 2º grau (A.x2 + B.x + C = 0). Calcule e apresente
na tela as raízes dessa equação, considerando os três casos possíveis: Delta maior que zero (duas raízes
reais), Delta igual a zero (uma raiz) e Delta menor que zero (não há raízes reais).
*/

float baskhra(float A, float B, float C) {

    float delta;
    delta = (B * B) - 4*A*C;

     return delta;
}

int main() {
    float A,B,C,delta,raiz1,raiz2;


    printf("Digite o primeiro coeficiente: ");
    scanf("%f", &A);

    printf("Digite o segundo coeficiente: ");
    scanf("%f", &B);

    printf("Digite o terceiro coeficiente: ");
    scanf("%f", &C);

    delta = baskhra(A,B,C);


    if(delta > 0){
        printf("DELTA: %.0f, eh maior que Zero\n", delta);
        raiz1 = (-B + sqrt(delta)) / (2 * A);
        raiz2 = (-B - sqrt(delta)) / (2 * A);
        printf("AS raizes sao: %.0f|%.0f",raiz1,raiz2);

    }else if(delta == 0){
        printf("DELTA: %.0f, eh igual a zero", delta);
        raiz1 = (-B/(2 * A));
        printf("A raiz eh: %.0f",raiz1);

    }else{
        printf("DELTA: %.0f, eh menor que zero", delta);
        raiz1 = (-B/(2 * A));
        raiz2 = (sqrt(-delta)/ (2 * A));
        printf("As raizes sao: %.0f + %.0f|%.0f - %.0f\n",raiz1,raiz2,raiz1,raiz2);
    }

    getchar();
    return 0;
}
