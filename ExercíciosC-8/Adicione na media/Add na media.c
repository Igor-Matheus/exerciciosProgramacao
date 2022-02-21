#include <stdio.h>

double AdicioneNaMedia(double valor){
    static double soma = 0
    static int quantidade = 0;

    quantidade++;
    soma += valor;

    return soma / quantidade;
}

int main(void){
    double valor, mediaAtual;
    int n, i;

    printf("Quantos valores vai inserir? ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        scanf("%lf", &valor);

        mediaAtual = AdicioneNaMedia(valor);

        printf("\tA media atual eh %.1lf\n", mediaAtual);
    }
    return 0;
}
