#include <stdio.h>
#define TAM_ARRAY 10

/*int main(void){ /** Quest�o 1 comce�a aqui. */
    /*int valor[TAM_ARRAY] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, soma = 0;

    printf("Elementos em ordem crescente:\n");
    for(i = 0; i < TAM_ARRAY; i++){
        soma += valor[i];
        printf("\t%d ", valor[i]);
    }

    printf("\n\nElementos em ordem decrescente:\n");

    for(i = TAM_ARRAY-1; i >= 0; i--){
        printf("\t%d ", valor[i]);
    }

    printf("\n\nElemento na quinta posicao: %d\n", valor[4]);

    printf("\nElementos dos indices impares:\n");

    for(i = 1; i < TAM_ARRAY; i += 2){
        printf("\t%d ", valor[i]);
    }

    printf("\n\nSoma dos valores armazenados: %d\n", soma);

    return 0;
} /** Quest�o 1 termina aqui. */


double MediaArray(int valor[], int tamanho){ /** Quest�o 2 at� a quest�o 6. */
    int i, soma = 0;

    for(i = 0; i < tamanho; i++){
        soma += valor[i];
    }
    return (double) soma / tamanho;
}

int EmArray(int valor[], int tamanho, int elemento){
    int i;

    for(i = 0; i < tamanho; i++){
        if (valor[i] == elemento){
            return 1;
        }
    }
    return 0;
}

int MaximoValorArray(int valor[], int tamanho){
    if (tamanho <= 0){
        return -1;
    }

    int maior = valor[0], i;

    for(i = 1; i < tamanho; i++){
        if (valor[i] > maior){
            maior = valor[i];
        }
    }
    return maior;
}

int EhArrayOrdenado(int valor[], int tamanho){
    int i, flag;

    flag = 1;
    for(i = 1; i < tamanho; i++){
        if (valor[i] < valor[i-1]){
            flag = 0;
        }
    }
    if (flag){
        return 1;
    }

    flag = 1;
    for(i = 1; i < tamanho; i++){
        if (valor[i] > valor[i-1]){
            flag = 0;
        }
    }
    if (flag){
        return -1;
    }
    return 0;
}

int main(void){
    int valor[TAM_ARRAY];
    int elemento, i, soma = 0;

    printf("Digite os 10 valores: ");

    for(i = 0; i < TAM_ARRAY; i++){
        scanf("%d", &valor[i]); //Quest�o 2: usu�rio escolhe os elementos do Array.
    }

    printf("\nElementos em ordem crescente dos indices:\n");
    for(i = 0; i < TAM_ARRAY; i++){
        soma += valor[i];
        printf("\t%d ", valor[i]);
    }

    printf("\n\nElementos em ordem decrescente dos indices:\n");
    for(i = TAM_ARRAY-1; i >= 0; i--){
        printf("\t%d ", valor[i]);
    }

    printf("\n\nElemento na quinta posicao: %d\n", valor[4]);

    printf("\nElementos dos indices impares:\n");
    for(i = 1; i < TAM_ARRAY; i += 2){
        printf("\t%d ", valor[i]);
    }

    printf("\n\nSoma dos valores armazenados: %d\n", soma);

    printf("\nMedia dos valores: %.2lf\n", MediaArray(valor, TAM_ARRAY)); //Quest�o 3: fun��o que retorna a
                                                                          //m�dia dos elementos do Array.
    printf("\nDigite o elemento a ser procurado no Array: ");
    scanf("%d", &elemento);

    if (EmArray(valor, TAM_ARRAY, elemento) == 1){ //Quest�o 4: fun��o booleana que
        puts("Presente no Array.");                //informa se o elemento est� ou
    }else{                                         //presente no Array.
        puts("Nao se encontra no Array.");
    }

    printf("\nValor do maior elemento no Array: %d\n", MaximoValorArray(valor, TAM_ARRAY));
                                                      //Quest�o 5: fun��o que retorna
                                                      //o maior valor do Array.

    printf("\nO Array%seh ordenado.\n", EhArrayOrdenado(valor, TAM_ARRAY)? " " : " nao ");
    switch(EhArrayOrdenado(valor, TAM_ARRAY)){                 //Quest�o 6: fun�a� que diz
        case -1:                                               //se o Array � ordenado ou n�o.
            printf("\tOBS: Ordenado em ordem decrescente.\n");
            break;
        case 1:
            printf("\tOBS: Ordenado em ordem crescente.\n");
            break;
    }
    return 0;
}






