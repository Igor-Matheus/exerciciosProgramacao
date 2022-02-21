#include <stdio.h>
#include "math.h"

double EhTrianguloRetangulo(double a, double b, double c){



}

double FormaTrianguloRetangulo(double a, double b, double c){



}

int main(void){
    double a, b, c, ehTriangulo, novoValor;

    printf("Digite o valor para o cateto a: ");
    scanf("%lf", &a);
    printf("Digite o valor para o cateto b: ");
    scanf("%lf", &b);
    printf("Digite o valor para a hipotenusa: ");
    scanf("%lf", &c);

    if (a > 0 && b > 0 && c > 0){

        ehTriangulo = EhTrianguloRetangulo(a, b, c);

        if (ehTriangulo == 1){
            printf("Eh um triangulo retangulo.\n");
        }
        if (ehTriangulo == 0){
            printf("Nao eh um triangulo retangulo.\n");
        }

    }else if (a <= 0 || b <= 0 || c <= 0){

        novoValor = FormaTrianguloRetangulo(a, b, c);



    }


    return 0;
}
