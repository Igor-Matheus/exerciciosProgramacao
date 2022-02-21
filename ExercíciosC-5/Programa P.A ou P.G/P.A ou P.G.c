#include <stdio.h>

int main(void){
    char c;
    float t1, r, n, i, pa, pg, soma;

    printf("Digite (a) para progressao aritmetica ou\n");
    printf("digite (g) para progressao geometrica: ");
    scanf("%c", &c);
    printf("Digite o primeiro termo da progressao: ");
    scanf("%f", &t1);
    printf("Digite a razao para a progressao: ");
    scanf("%f", &r);
    printf("Digite um numero natural para a quantidade de termos: ");
    scanf("%f", &n);

    if (c =='a'){
        pa = (t1 - r);
        soma = 0;
        for(i = 1; i <= n; i = i + 1){
            pa = pa + r;
            soma = soma + pa;
            printf("%.0f\n", pa);
        }
        printf("Soma dos elementos = %.0f\n", soma);

    }else if(c =='g'){
        pg = (t1 / r);
        soma = 0;
        for(i = 1; i <= n; i = i + 1){
            pg = pg * r;
            soma = soma + pg;
            printf("%.0f\n", pg);
        }
        printf("Soma dos elementos = %.0f\n", soma);
    }

    return 0;
}
