#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor,*NEG, *POS ,N, Num, contPos = 0, contNeg = 0;

    printf("Digite o tamanho do vetor: \n");

    do{
        scanf("%d", &N);

        if(N < 1 || N > 50){
            printf("Os valores devem ser maior que 1 ou menores que 50\n");
        }

    }while(N < 1 || N > 50);


    vetor = (int *)malloc(N * sizeof(int));

    printf("Prencha o vetor\n");

    for(int i = 0; i < N; i++){
        scanf("%d", &Num);
        vetor[i] = Num;
        if(Num >= 0){
            contPos++;
        } else {
            contNeg++;
        }
    }
    NEG = (int *)malloc(contNeg * sizeof(int));
    POS = (int *)malloc(contPos * sizeof(int));

    int posindex = 0;
    int negindex = 0;

    for(int i = 0; i < N; i++){
        if(vetor[i] < 0){
            NEG[negindex++] = vetor[i];
        }else{
            POS[posindex++] = vetor[i];
        }
    }

    printf("Os valores digitados \n");
    for(int i = 0; i < N; i++){
        printf("%d", vetor[i]);
    }

    printf("\n Os valores positivos \n");
    for(int i = 0; i < contPos; i++){
        printf("%d", POS[i]);
    }


    printf("\n Os valores negativos \n");
    for(int i = 0; i < contNeg; i++){
        printf("%d", NEG[i]);
    }

    free(vetor);
    free(NEG);
    free(POS);

    return 0;
}
