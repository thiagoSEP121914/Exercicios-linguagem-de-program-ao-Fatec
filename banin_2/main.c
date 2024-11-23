#include <stdio.h>
#include <stdlib.h>


int main() {
    int N = 0;

    while(N <= 0){
        printf("O valor de N deve ser maior que zero \n");
        scanf("%d", &N);

    }

    int *vetor;
    vetor = (int *)malloc(N * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < N; i++){
        vetor[i] = rand() % 1001;
    }

    FILE *file = fopen("Banana.txt", "w");
    if(file == NULL){
        perror("Erro ao abir o arquivo");
        free(vetor);
    }

    for(int i = 0; i < N; i++){
        fprintf(file, "%d\n", vetor[i]);
    }
    fclose(file);
    free(vetor);

    return 0;
}
