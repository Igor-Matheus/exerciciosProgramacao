#include <stdio.h>

int main(void){
    int n, ant1, ant2, atual, i;

    printf("Digite o numero de termos para a sequencia de Fibonacci: ");
    scanf("%d", &n);
    printf("\nOs primeiros %d termos da sequencia Fibonacci sao: ", n);

    for(i = 1; i <= n; i = i + 1){
        if (i == 1 || i == 2){
            atual = 1;
        }else{
            atual = ant2 + ant1;
        }

        if (i > 1 && i != n){
            printf(", ");
        }

        if (i == n && n > 1){
            printf(" e ");
        }

        printf("%d", atual);
        ant2 = ant1;
        ant1 = atual;
    }

    printf(".\n");

    return 0;
}
