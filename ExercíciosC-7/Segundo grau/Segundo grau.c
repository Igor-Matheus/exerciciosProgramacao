/**
 ============================================================================
 Nome      : Segundo grau.c
 Autor     : Igor
 Versao    : 1.0
 Copyright : CC BY 4.0
 Descricao : O programa le os coeficientes a, b e c de uma equação do segundo
 grau e calcula o resultado da mesma.
 ============================================================================
 */
#include <stdio.h>
#include "math.h"

/****
* Delta(): Calcula o delta da equação.
*
* Parametros:
*    a (entrada): coeficiente a.
*    b (entrada): coeficiente b.
*    c (entrada): coerficiente c.
* Retorno: retorna sempre o delta a partir dos
  coeficientes recebidos.
****/

float Delta(float a, float b, float c){
    float delta = (pow(b,2) - 4 * a * c);
    return delta;
}

/****
* RaizX1(): Calcula a primeira raiz da equação.
*
* Parametros:
*    a (entrada): coeficiente a.
*    b (entrada): coeficiente b.
*    delta (entrada): delta calculado.
* Retorno: retorna sempre o valor da raiz x1.
****/

float RaizX1(float a, float b, float delta){
    float x1 = (-b + sqrt(delta))/ (2*a);
    return x1;
}

/****
* RaizX2(): Calcula a segunda raiz  da equação.
*
* Parametros:
*    a (entrada): coeficiente a.
*    b (entrada): coeficiente b.
*    delta (entrada): delta calculado.
* Retorno: retorna sempre o valor da raiz x2.
****/

float RaizX2(float a, float b, float delta){
    float x2 = (-b - sqrt(delta))/ (2*a);
    return x2;
}

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

    delta = Delta(a, b, c);
    x1 = RaizX1(a, b, delta);
    x2 = RaizX2(a, b, delta);

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
