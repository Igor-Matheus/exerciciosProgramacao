/**
 ============================================================================
 Nome      : q3-completarFuncoes.c
 Autor     : lincoln
 Versao    : 1.0
 Copyright : CC BY 4.0
 Descricao : Exercicio para completar com definicoes de funcoes.
 ============================================================================
 */
#include <stdio.h>

/****
* SomaAteN(): Calcula a soma de todos valores de 0 ate n.
*
* Parametros:
*    n (entrada): o valor do numero natural n, ate onde a soma sera feita.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               -1 (menos 1):   quando o parametro n nao for um natural.
*               valor natural:  valor da soma ate n quando n for natural.
****/
int SomaAteN(int n){
    int soma = 0, i;    /* A soma eh uma variavel que auxilia no calculo do *
                         * valor da funcao. Ela deve ser definida aqui e nao*
                         * como parametro. O mesmo vale pro i.              *
                         * Os parametros contem apenas os valores que a     *
                         * funcao precisa para calcular os valores, e o     *
                         * minimo possivel.                                 */

    if (n < 0)          /* Normalmente colocamos as verificacoes dos casos  */
        return -1;      /* excepcionais logo no inicio da funcao.           */

    for (i = 0; i <= n; i++){
        soma = soma + i;
    }

    return soma;
}

/****
* Fatorial(): Calcula o fatorial de um natural n.
*
* Parametros:
*    n (entrada): o valor do numero natural n.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               -1 (menos 1):   quando o parametro n nao for um natural.
*               valor natural:  valor de n! quando n for natural.
****/
int Fatorial(int n){
    int fat = 1, i;

    if (n < 0)
        return -1;

    if (n == 0 || n == 1)   /* tambem podemos colocar condicoes para os */
        return 1;           /* valores fixos/definidos.                 */

    for(i = 1; i <= n; i++){
        fat = fat * i;
    }

    return fat;
}

/****
* EhPar(): Indica se um valor inteiro eh par ou impar.
*
* Parametros:
*    x (entrada): o valor de um inteiro x.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               1 (verdadeiro): quando x for par.
*               0 (falso):      quando x for impar.
****/
int EhPar(int x){
    return x % 2 == 0;  /* o resultado da expressao eh 1 ou 0 */
}

/****
* EhDivisivel(): Indica se um numero eh divisivel por outro.
*
* Parametros:
*    a (entrada): um valor inteiro.
*    b (entrada): um valor inteiro.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               1 (verdadeiro): quando a for divisivel por b.
*               0 (falso):      quando a NAO for divisivel por b.
****/
int EhDivisivel(int a, int b){
    if (a % b == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(void) {
    int n, soma, i;

    printf("Digite um numero inteiro N: ");
    scanf("%d", &n);

    soma = SomaAteN(n);
    printf("A soma de 1 ateh N eh: %d\n", soma);

    printf("%d! = %d\n", n, Fatorial(n));
    if (EhPar(n)){
        printf("%d eh par\n", n);
    }else{
        printf("%d eh impar\n", n);
    }

    for (i = 2; i <= 15; i++){
        if (EhDivisivel(n, i)){
            printf("%d eh divisivel por %d\n", n, i);
        }else{
            printf("%d nao eh divisivel por %d\n", n, i);
        }
    }

	return 0;
}

