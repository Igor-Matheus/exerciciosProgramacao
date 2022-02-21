#include <stdio.h>

int main(void){
    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if (idade >= 21 && idade < 60){
        printf("se tem %d anos, voce eh adulto", idade);
    }else if (idade < 21){
        printf("se tem %d anos, voce eh jovem", idade);
    }else {
        printf("se tem %d anos, voce eh idoso", idade);
    }
    return 0;
}
