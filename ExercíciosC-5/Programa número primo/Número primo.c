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

//sugest�o: A �nica forma de saber se um n�mero � ou n�o primo � fazendo as
//divis�es necess�rias. Ent�o, seu programa deve contar quantas divis�es com resto
//igual a zero ocorrem ao dividir o n por todos os n�meros do intervalo [1, n]. O
//n�mero n ser� primo se apenas 2 divisores forem encontrados.]
