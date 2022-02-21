#include <stdio.h>

int main(void){
    int valor, quant, resto;

    printf("Em reais, digite o valor: ");
    scanf("%d", &valor);

    quant = valor / 100;
    resto = valor % 100;
    if (quant > 0){
        printf("%d nota(s) de 100\n", quant);
    }

    valor = resto;
    quant = valor / 50;
    resto = valor % 50;
    if (quant > 0){
        printf("%d notas(s) de 50\n", quant);
    }

    valor = resto;
    quant = valor / 20;
    resto = valor % 20;
    if (quant > 0){
        printf("%d notas(s) de 20\n", quant);
    }

    valor = resto;
    quant = valor / 10;
    resto = valor % 10;
    if (quant > 0){
        printf("%d notas(s) de 10\n", quant);
    }

    valor = resto;
    quant = valor / 5;
    resto = valor % 5;
    if (quant > 0){
        printf("%d notas(s) de 5\n", quant);
    }

    valor = resto;
    quant = valor / 2;
    resto = valor % 2;
    if (quant > 0){
        printf("%d notas(s) de 2\n", quant);
    }

    valor = resto;
    quant = valor / 1;
    resto = valor % 1;
    if (quant > 0){
        printf("%d notas(s) de 1\n", quant);
    }

    return 0;
}
