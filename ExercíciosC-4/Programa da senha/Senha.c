#include <stdio.h>
#include <stdlib.h>

int main(void){
    int senha;

    scanf("%d", &senha);

    while ( senha < 2002 || senha > 2002){
        printf("Senha Invalida\n");
        scanf("%d", &senha);
    }

    printf("Acesso Permitido\n");

    return 0;
}
