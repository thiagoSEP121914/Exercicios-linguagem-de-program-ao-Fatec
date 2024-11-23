#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que contenha um vetor
denominado A, com 5 elementos inteiros e inicializados
com os valores {19, 23, 29, 31, 37}.
Faça duasexibições deste vetor na tela: a primeira em
ordem normal e a segunda de trás para frente.
*/

void exibir(int *vet){

    int *ptr = vet;
    int tam = 0;

    while(*ptr){
        printf("%d ", *ptr);
        ptr++;
        tam++;
    }
    tam - 1;
    printf("\n");
    for(int i = tam; i >= 0; i--){
        printf("%d ",vet[i]);
    }
}

int main(){
    int A[5] = {19, 23, 29, 31, 37};

    exibir(A);

    getchar();
    // codigo que imprime um vetor em ordem normal e inversa
    return 0;
}
