#include <stdio.h>

int main(void){
    float peso, altura, imc;

    printf("Vamos descobrir seu imc!\n");
    printf("Digite o seu peso, em quilogramas: ");
    scanf("%f", &peso);
    printf("Digite a sua altura, em metros: ");
    scanf("%f", &altura);

    imc = (peso) / (altura * altura);

    if (imc <= 18.5){
        printf("Seu imc eh: %.2f\n", imc);
        printf("Voce esta com baixo peso.");
    }else if (imc > 18.5 && imc <= 25){
        printf("Seu imc eh: %.2f\n", imc);
        printf("Voce esta com peso normal.");
    }else if (imc > 25 && imc <= 30){
        printf("Seu imc eh: %.2f\n", imc);
        printf("Voce esta com sobrepeso.");
    }else{
        printf("Seu imc eh: %.2f\n", imc);
        printf("Voce esta com obesidade.");
    }

    return 0;
}
