#include <stdio.h>

int main(void){
    int x, y, z;

    printf("Qual dos 3 numeros inteiros eh o maior?\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &x);
    printf("Digite o segundo numero: ");
    scanf("%d", &y);
    printf("Digite o terceiro numero: ");
    scanf("%d", &z);

    if (x > y && x > z){
        printf("%d eh maior", x);
    }else if (y > x && y > z){
        printf("%d eh maior", y);
    }else if (z > x && z > y){
        printf("%d eh maior", z);
    }else if (x == y && z > x){
        printf("%d eh maior", z);
    }else if (x == y && x > z){
        printf("%d eh maior", x);
    }else if (x == z && y > x){
        printf("%d eh maior", y);
    }else if (x == z && x > y){
        printf("%d eh maior", x);
    }else if (y == z && x > y){
        printf("%d eh maior", x);
    }else if (y == z && y > x){
        printf("%d eh maior", y);
    }else{
        printf("Todos sao iguais!");
    }
    return 0;
}
