#include <stdio.h>

int main(void){
    float x, y;

    printf("Digite o primeiro numero: ");
    scanf("%f", &x);
    printf("Digite o segundo numero: ");
    scanf("%f", &y);

    if (x < y){
        printf("%.2f eh menor", x);
    }else if (x == y){
        printf("Os numeros sao iguais!");
    }else{
        printf("%.2f eh menor", y);
    }

    return 0;
}
