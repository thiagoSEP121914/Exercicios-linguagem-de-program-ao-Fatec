#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa para calcular o sal�rio
bruto de um profissional que recebe por hora, sabendo que ele ganha R$ 14,25/h e trabalhou 163 horas
normais e 20 horas extras (pagam o dobro). N�o use valores fixos no programa. Ao inv�s disso fa�a a
leitura dos dados de entrada em vari�veis para o valor hora, o n�mero de horas normais e o n�mero de
horas extras
*/

float calcular_salario(float salario,float hora, float hora_extra) {

        float tot_salario, salario_normal, salario_extra = 0;

        salario_normal = salario * hora;
        salario_extra = (salario * 2)* hora_extra;
        tot_salario = salario_normal + salario_extra;

        return tot_salario;
}



int main() {

    float salario, salario_bruto, hora_trabalhada,hora_extra;

    printf("Digite o salario/hora do funcionario: ");
    scanf("%f", &salario);

    printf("Digite a quantidade de horas trabalhadas: ");
    scanf("%f", &hora_trabalhada);

    printf("Digite a quantidade de horas extras: ");
    scanf("%f", &hora_extra);

    salario_bruto = calcular_salario(salario,hora_trabalhada,hora_extra);

    printf("O salario bruto do funcionario eh: R$%.4f", salario_bruto);

    getchar();

    return 0;
}
