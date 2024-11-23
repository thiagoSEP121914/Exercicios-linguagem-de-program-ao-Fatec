#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que contenha um vetor
com tamanho 10. O programa deve conter um laço no qual um valor X seja lido do teclado e colocado
no vetor. O laço deve terminar quando acontecer uma de duas situações: o valor digitado para X seja 0
(zero) ou quando todo o vetor for preenchido. Ao sair do laço mostre na tela os elementos do vetor,
sendo um em cada linha.
*/

void prencher(int *vet){
    int i = 0;

    while(i < 10){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &vet[i]);

        printf("\n");

        if(vet[i] == 0){
            break;
        }
        i++;
    }
}

void exibir(int *vet){
    int *ptr = vet;

    while(*ptr){
        printf("%d ", *ptr);
        ptr++;
    }
}

int main() {
    int vet[10];

    prencher(vet);
    exibir(vet);

    getchar();

    //programa que prenche um vetor de 10 posicoes ate que seja maior que 10 ou igual a zero
    return 0;
}
