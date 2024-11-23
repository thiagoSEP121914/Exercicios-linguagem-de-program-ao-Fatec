#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que leia um número inteiro N e carrega um vetor com N números inteiros digitados no teclado.
O programa não deve aceitar um número digitado que já esteja inserido no vetor, sendo que se isto ocorrer deve ser
emitida uma mensagem informando que o valor já existe. Por fim, exibir na tela o vetor resultante.
*/


int valorExiste(int *vetor, int tam, int num) {
    // funcao que retorna se o valor ja existe ou nao
    for(int i; i < tam; i++){
        if(vetor[i] == num) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int num;
    int *vet;
    int valor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &num);

    vet = (int *)malloc( num * sizeof(int));

    printf("Digite os valores do vetor \n");
    for(int i = 0; i < num; i++){
       printf("\nDigite o valor do vetor %d: ", i  + 1);
        scanf("%d", &valor);

        // laco que ira ler enquanto o numero lido ja estiver no vetor
        while(valorExiste(vet, i , valor) == 0){
           // se a funcao retornar 0 o valor existe no vetor
            printf("O valor ja existe, digite novamente: ");
            scanf("%d", &valor);
        }
       // se o numero nao existir entao o vetor recebe o valor
        vet[i] = valor;
    }

    printf("O valores do veotr sao \n");
    for(int i = 0; i < num; i++){
        printf("%d", vet[i]);
    }

}
