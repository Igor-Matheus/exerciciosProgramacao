#include <stdio.h>

int main(void){
    int anterior, atual, rAtual, rGeral , ehPa;

    printf("************ Descubra se a sequencia eh uma P.A *****************\n");
    printf("\nDigite uma sequencia de valores inteiros de quantos termos quiser.\n");
    printf("Quando terminar a sequencia, digite o numero (-1).\n");
    scanf("%d", &anterior);
    scanf("%d", &atual);

    rGeral = atual - anterior;
    ehPa = 1;

    do{
        anterior = atual;
        scanf("%d", &atual);
        rAtual = atual - anterior;

        if(atual != -1 && rAtual != rGeral){
            ehPa = 0;
        }
    }while(atual != -1);

    if(ehPa == 1){
        printf("\nFoi uma P.A de razao %d.\n", rGeral);
    }else{
        printf("\nNao foi P.A!\n");
    }

    return 0;
}
