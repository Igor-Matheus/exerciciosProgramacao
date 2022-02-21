#include <stdio.h>
#include <math.h>

int main(void){
    float a, b, c, delta, x1, x2;

    printf("Vamos descobrir as raizes de uma equacao de segundo grau!\n");
    printf("Digite o valor do coeficiente a: ");
    scanf("%f", &a);

    if (a==0){
        puts("nao eh do segundo grau!");
        return 1;
    }else{
        printf("Coeficiente b: ");
        scanf("%f", &b);
        printf("Coeficiente c: ");
        scanf("%f", &c);
    }

    delta = (pow(b,2) - 4 * a * c);
    printf("Delta eh igual a: %.1f\n", delta);

    x1 = (-b + sqrt(delta))/ (2*a);
    x2 = (-b - sqrt(delta))/ (2*a);

    if (delta < 0){
        printf("A equacao nao possui raizes reais, o delta eh negativo!");
        return 2;
    }
    if (delta == 0){
        printf("O delta eh zero, logo, so existe uma raiz.\n");
        printf("x = %.1f", x1);
    }else{
        printf("x1 = %.1f e x2 = %.1f", x1, x2);
    }

    return 0;
}
