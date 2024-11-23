#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *file = fopen("messi.txt", "r");
   int vetor[20];
   int i = 0, num;

    while(fscanf(file, "%d", &num)!= EOF && i < 10){
        vetor[i] = num;
        i++;
    }

    for(int j = 0; j < i ; j++){
        printf("%d\n", vetor[j]);
    }
   fclose(file);
    return 0;
}
