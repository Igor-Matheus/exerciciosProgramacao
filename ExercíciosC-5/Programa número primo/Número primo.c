#include <stdio.h>

int main(void){
    int n, r, i, resto0;

    printf("Descubra se o numero que inserir eh primo ou nao.\n");
    printf("Digite um numero natural: ");
    scanf("%d", &n);

    resto0 = 0;
    for (i = 1; i <= n; i = i + 1){
        r = (n % i);
        if (n % i == 0){
            resto0 = resto0 + 1;
        }
    }

    if (resto0 == 2){
        printf("\n%d eh um numero primo!", n);
    }else{
        printf("\n%d nao eh um numero primo!", n);
    }

    return 0;
}

//sugestão: A única forma de saber se um número é ou não primo é fazendo as
//divisões necessárias. Então, seu programa deve contar quantas divisões com resto
//igual a zero ocorrem ao dividir o n por todos os números do intervalo [1, n]. O
//número n será primo se apenas 2 divisores forem encontrados.]
