#include <stdio.h>
#include <stdlib.h>

int JaExiste(int *vetor, int tam, int num) {
    for(int i = 0; i < tam; i++){
        if(vetor[i] == num) {
            return 1;
        }
    }

    return 0;
}


int main(){
    FILE *arquivo = fopen("messi.txt", "r");
    int *vetor = NULL;

    if(arquivo == NULL){
        printf("Nao for possivel abrir o arquivo!");
    }

    int tam = 0;
    int num;

    while(fscanf(arquivo, "%d", &num)!= EOF){
        vetor = (int *)realloc(vetor, tam * sizeof(int));
        vetor[tam] = num;
        tam++;
    }
    fclose(arquivo);
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    int temp[tam];
    int novoTam = 0;

    printf("\nEliminando duplicatas \n");
    for(int i = 0; i < tam; i++){
        if(!JaExiste(vetor, novoTam, vetor[i])){
            vetor[novoTam] = vetor[i];
            novoTam++;

        }
    }
    vetor = (int *)realloc(vetor, novoTam * sizeof(int));

    for(int i = 0; i < novoTam; i++){
        printf("%d ", vetor[i]);

   }

    FILE *NovoArquivo = fopen("Banana.txt", "w");
    if(NovoArquivo == NULL){
        printf("Nao foi possive abri a porra do arquivo");
    }

    for(int i = 0; i < novoTam; i++){
        fprintf(NovoArquivo, "%d\n", vetor[i]);
    }
    fclose(NovoArquivo);

    free(vetor);

    return 0;
}
