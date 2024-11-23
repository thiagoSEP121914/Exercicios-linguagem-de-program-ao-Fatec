#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
Escreva um programa que leia do teclado um
número real R. Use o tipo double para R. Calcule e mostre na tela com três casas decimais:
a. A área do círculo de raio R
b. O volume da esfera de raio R
*/

int main() {
    double R;

    printf("Digite o um valor: ");
    scanf("%lf", &R);

    printf("A area do circulo de R eh: %.3f\n", M_PI * pow(R, 2));
    printf("O volume da esfera do raio eh: %.3f\n",(4 * M_PI * pow(R,3))/3);

    return 0;
}
