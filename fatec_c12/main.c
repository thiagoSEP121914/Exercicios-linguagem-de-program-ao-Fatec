#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que contenha um vetor
V inicializado com os valores a seguir. Neste programa deve haver um laço onde é feita a
leitura de um valor inteiro A. Este laço deve permanecer em execução enquanto o valor de A for
maior que zero. Parac ada valor de A informe se seu valor está no vetor e em qual posição.
int V[15] = {17, 4, 53, 38, 22, 40, 25, 16, 31, 64, 45, 32, 20, 12, 29};
*/

void exibirVetor(int *vet, int *var) {
    int *ptr = vet;
    int cont = 0;

    while(*var != 0){
        printf("Digite o valor de A: ");
        scanf("%d", var);
        ptr = vet;
        cont = 0;

        while(*ptr){
            if(*var == *ptr){
                printf("O valor estar na posicao %d\n", cont+1);
            }

            ptr++;
            cont++;
        }
    }
}

int main() {
    int v[15] = {17, 4, 53, 38, 22, 40, 25, 16, 31, 64, 45, 32, 20, 12, 29};
    int A = 1;

    exibirVetor(v, &A);

    getchar();
    // programa que ler um valor A e compara com com numero de um vetor V
    return 0;
}
