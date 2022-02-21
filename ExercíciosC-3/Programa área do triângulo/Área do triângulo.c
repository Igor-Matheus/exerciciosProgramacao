#include <stdio.h>

int main(void){
    int base, altura;
    float area;

    printf("Digite o valor da base: ");
    scanf("%d", &base);
    printf("Digite o valor da altura: ");
    scanf("%d", &altura);

    area = (base * altura) / 2.0;

    printf("A area do triangulo de base %d e altura %d eh: %.2f.\n", base, altura, area);

    return 0;
}
