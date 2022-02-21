#include <stdio.h>

int main(void){
    float nota1, nota2, nota3;
    float media;

    printf("Digite o valor da primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite o valor da segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite o valor da terceira nota: ");
    scanf("%f", &nota3);

    media=(nota1 + nota2 + nota3)/3;

    printf("A media das suas notas tem valor: %.1f", media);

    return 0;
}
