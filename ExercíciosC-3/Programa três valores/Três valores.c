#include <stdio.h>

int main(void){
    int x, y, z, soma, produto, media;

    printf("Vamos descobrir a soma, produto e a media de 3 numeros inteiros!\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &x);
    printf("Digite o segundo numero: ");
    scanf("%d", &y);
    printf("Digite o terceiro numero: ");
    scanf("%d", &z);

    soma = (x + y + z);
    produto = (x * y * z);
    media = (soma) / 3;

    printf("A soma dos numeros eh: %d\n", soma);
    printf("O produto dos numeros eh: %d\n", produto);
    printf("A media dos numeros eh: %d", media);

    return 0;
}
