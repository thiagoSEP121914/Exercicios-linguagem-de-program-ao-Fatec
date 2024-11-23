#include <stdio.h>
#include <stdlib.h>

int main(){
   FILE *file = fopen("messi.txt", "r");

    if(file == NULL){
        perror("Erro ao abrir o arquivo.");
        return 1;
    }

   int *vetor = NULL;
   int tamanho = 0;
   int numero;

   while(fscanf(file, "%d", &numero)== 1){
        int *temp = realloc(vetor, (tamanho + 1) * sizeof(int));
        if(temp == NULL){
            perror("Erro ao realocar memoria!");
            free(vetor);
            fclose(file);
            return 1;
        }
        vetor = temp;
        vetor[tamanho] = numero;
        tamanho++;

   }

    fclose(file);

    printf("Vetor lido na tela: \n");

    for(int i = 0; i < tamanho; i++){
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}
