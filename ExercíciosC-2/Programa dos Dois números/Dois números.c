#include <stdio.h>

int main(void){
    int a, b;

    printf("Vamos ver qual dos dois numeros eh menor!\n");
    printf("Qual o numero a?: ");
    scanf("%d", &a);
    printf("Qual o numero b?: ");
    scanf("%d", &b);

    if ( a < b ){
        printf("%d eh menor\n", a);
    }else{
        printf("%d eh menor\n", b);
    }

    return 0;
}

