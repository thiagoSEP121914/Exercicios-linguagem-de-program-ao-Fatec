#include <stdio.h>
#include <stdlib.h>



int main() {
  int R,N,P,contador = 0;


  printf("Digite A quantidade de termos: ");
  scanf("%d", &N);

  printf("Digite o primeiro termo: ");
  scanf("%d", &P);

  printf("Digite a RAZAO: ");
  scanf("%d", &R);

  for(int i = 0; i < N; i++){
        contador+= P;
        printf("%d", P);
        P = P * R;
        printf(" ");
  }

    printf("\nA soma dos termos eh: %d\n", contador);
    getchar();
    return 0;
}
