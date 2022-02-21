#include <stdio.h>

int main(void){
    float diametro, raio, area, perimetro;

    printf("Descobriremos, a partir do diametro, qual o valor em metros\n");
    printf("do raio, area e perimetro de um circulo.\n");
    printf("Digite o valor do diametro: ");
    scanf("%f", &diametro);

    raio = (diametro) / 2;
    area = 3.14 * raio * raio;
    perimetro = 2 * 3.14 * raio;

    printf("Raio = %.2f\n", raio);
    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f", perimetro);

    return 0;
}
