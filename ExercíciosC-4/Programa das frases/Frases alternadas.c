#include <stdio.h>

int main(void){
    int i;

    for( i = 1; i <= 200; i = i + 1){
        if( i % 2 == 0){
            printf("Quem nao escreve programas nao aprende a programar\n");

        }else{
            printf("So aprende a programar quem escreve programas\n");

        }
    }
    return 0;
}
