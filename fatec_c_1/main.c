#include <stdio.h>
#include <stdlib.h>


/*
Escreva um programa que leia as medidas de
base e altura de um triângulo e calcule sua área. Use variáveis que comportem números reais, tanto
para os dados de entrada como para o resultado.
*/

float area_triangulo(float altura, float base) {

    float area = 0;
    area =  (altura * base)/2;

    return area;
}


int main() {
    float altura,base,Area_triang;

    printf("===============================\n");
    printf("\tAREA DO TRIANGULO\n");
    printf("===============================\n");

    printf("Digite a base do triangulo: ");
    scanf("%f", &base);

    printf("Digite a altura do triangulo: ");
    scanf("%f", &altura);

    Area_triang = area_triangulo(altura,base);

    printf("A area do triangulo eh: %2.fcm", Area_triang);

    getchar();
    return 0;
}
