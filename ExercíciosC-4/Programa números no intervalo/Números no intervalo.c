#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a, b;

    printf("Digite dois numeros inteiros positivos a e b,\n");
    printf("lembrando que o numero b deve ser maior ou igual ao a.\n");

    printf("Numero a: ");
    scanf("%d", &a);

    printf("Numero b: ");
    scanf("%d", &b);

    for( int i = a; a <= b; a = a + 1){
        printf("%d\n", a);
    }

    return 0;
}
