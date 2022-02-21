#include <stdio.h>

int main(void){
    float altura, comprimento, area, rendimento, volume, latas;

    printf("Vamos ver quantas latas de tinta precisaremos para pintar sua parede!\n");
    printf("Digite o valor, em metros, da altura da parede: ");
    scanf("%f", &altura);
    printf("Digite o valor, em metros, do comprimento da parede: ");
    scanf("%f", &comprimento);
    printf("Qual o rendimento da lata de tinta, em metro quadrado por litro?: ");
    scanf("%f", &rendimento);
    printf("Por ultimo, qual o volume, em litros, da lata de tinta?: ");
    scanf("%f", &volume);

    area = altura*comprimento;
    latas = (area/rendimento)/volume;

    printf("Precisaremos de: %.1f latas de tinta", latas);

    return 0;
}
