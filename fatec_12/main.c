#include <stdio.h>
#include <stdlib.h>

int main() {
    int totn = 0, totm = 0,num;

    do{
        printf("\nDigite um numero: ");
        scanf("%d", &num);
        if(num < 0){
            totn+= num;
        }else{

            totm+= num;
        }

    }while(num != 0);
    printf("Total dos positivos: %d \n", totm);
    printf("Total dos negativos: %d", totn);

    getchar();
    return 0;
}
