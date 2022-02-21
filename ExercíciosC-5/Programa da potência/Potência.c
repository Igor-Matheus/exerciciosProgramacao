#include <stdio.h>

int main(void){
    int i,base, expoente, resultado;

    printf("Vamos calcular, com numeros inteiros, uma potencia!\n");
    printf("Digite o valor da base: ");
    scanf("%d", &base);
    printf("Digite o valor do expoente: ");
    scanf("%d", &expoente);

    resultado = 1;
    for(i = 1; i <= expoente ; i = i + 1){
        resultado = resultado * base;
    }

    printf("O resultado de %d elevado a %d = %d", base, expoente, resultado);

    return 0;
}
