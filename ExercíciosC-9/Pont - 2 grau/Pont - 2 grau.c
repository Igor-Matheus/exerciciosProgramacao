#include <stdio.h>
#include "math.h"

int ResolveEquacao2Grau(float a, float b, float c, float *x1, float *x2){
    float delta;

    if (a==0){
        return -1;
    }
    delta = (pow(b,2) - 4 * a * c);

    if (delta < 0){
        return -2;

    }else{
        *x1 = (-b + sqrt(delta))/ (2*a);
        *x2 = (-b - sqrt(delta))/ (2*a);

        return 0;
    }
}

int main(void){
    float a, b, c, x1, x2;
    int resposta;

    printf("Vamos descobrir as raizes de uma equacao de segundo grau!\n");
    printf("\n\tDigite o valor do coeficiente a: ");
    scanf("%f", &a);
    printf("\n\tDigite o valor do coeficiente b: ");
    scanf("%f", &b);
    printf("\n\tDigite o valor do coeficiente c: ");
    scanf("%f", &c);

    resposta = ResolveEquacao2Grau(a, b, c, &x1, &x2);

    if (resposta == -1){
        puts("\n\tNao eh do segundo grau! Pois a = 0.");

    }else if (resposta == -2){
        puts("\n\tA equacao nao possui raizes reais, pois o delta eh negativo.");

    }else{
        printf("\n\tx1 = %.1f  \tx2 = %.1f\n", x1, x2);
    }
    return 0;
}
