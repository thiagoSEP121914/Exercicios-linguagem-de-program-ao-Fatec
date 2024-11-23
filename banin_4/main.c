#include <stdio.h>
#include <stdlib.h>

int NumExiste(int *vet, int num, int tam){

    for(int i = 0; i < tam; i++){
        if(vet[i] == num){
            return 1;
        }
    }

    return 0;
}

int main(){

    int N;

    printf("Digite o tamanho do vetor:");
    scanf("%d", &N);

    int *vetor = (int *)malloc(N * sizeof(int));
    int numero;
    int existe = 1;

    for(int i = 0; i < N; i++){
        printf("Digite o %d valor \n", i+1);
        while(existe == 1){
            scanf("%d", &numero);
            existe = NumExiste(vetor, numero, i);
            if(existe == 1){
                printf("O numero ja existe\n");
            }
        }
        vetor[i] = numero;
        existe = 1;
    }

    printf("Vetor prenchido com sucesso.\n");

    for(int i = 0; i < N; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}
