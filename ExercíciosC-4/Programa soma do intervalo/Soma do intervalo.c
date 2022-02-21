#include <stdio.h>
#include <stdlib.h>
int main(void){
    int M, N, aux, soma = 0;

    while(1){
        scanf("%d", &M);
        scanf("%d", &N);

        if(M > N){
            aux = M;
            M = N;
            N = aux;
        }

        if(M <= 0 || N <= 0){
            break;
        }

        while(1){
            soma += M;
            M++;
            if(N <= M){
                break;
            }
            printf("%d %d Sum=%d\n", M, N, soma);
        }
    }

    return 0;
}
