#include <stdio.h>
#include "math.h"

void CalculaHexagono(float l, float *area, float *perimetro){
    *area = ((3*l * l) * sqrt(3)) / 2;

    *perimetro = 6 * l;
}

int main(void){
    float lado, area, perimetro;

    printf("Digite, em metros, o valor que"
           " representa o lado do hexagono: ");

    scanf("%f", &lado);

    CalculaHexagono(lado, &area, &perimetro);

    printf("\n\tA area do hexagono eh: %.2f metros quadrados.\n\n", area);

    printf("\tO perimetro do hexagono eh: %.2f metros.\n", perimetro);

    return 0;
}
