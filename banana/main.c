#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void imprimir(int num) {

    printf("%d Divisivel por:\n", num);
    for(int i = 1; i < num; i++){
        if(num % i == 0){
            printf("%d", i);
        }
    }
}

int main() {
    int min,
        max,
        D;

    printf("Digite o valor de min:");
    scanf("%d", &min);

    printf("Digite o valor de Max:");
    do{
        scanf("%d", &max);
    }while(max < min);

    printf("Digite o valor de D:");
    do{
        scanf("%d", &D);

    }while(D < 0);

    int qtd = 0;
    for(int i = min; i < max; i++){
        for(int j = 1; j <=1; j++){
            if(i % j == 0){
                qtd++;
                if(qtd > 5){
                    imprimir(i);
                }
            }
        }
    }




    return 0;
}
