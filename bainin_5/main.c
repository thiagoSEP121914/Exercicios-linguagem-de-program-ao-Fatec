#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;

    printf("Digite o valor do vetor");
    scanf("%d", &N);

    srand(time(NULL));

    int *vetor = (int *)malloc(N * sizeof(int));
    if(vetor == NULL){
        printf("Erro ao realocar memoria");
        free(vetor);
    }

    for(int i = 0; i < N; i++){
         vetor[i] = rand() % 1001;
    }

    for(int i = 0; i < N; i++){
        printf("%d ", vetor[i]);
    }
    int X;

    printf("\nDigite um numero:");
    scanf("%d", &X);

    int tam = 0;
    int numero;

    for(int i = 0; i < N; i++){
        if(vetor[i] != X){
            vetor[tam] = vetor[i];
            tam++;
        }
    }

    int *temp = realloc(vetor, tam * sizeof(int));

    if(temp == NULL){
        printf("Erro ao realocar memoria \n");
        free(vetor);
    }
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    free(vetor);

    return 0;
}
