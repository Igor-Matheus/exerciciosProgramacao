#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, numeroCorreto, tentativas;

    srand(time(NULL));
    numeroCorreto = rand() % 100;

	puts("Bem-vindo!");
	puts("Voce tem apenas 5 tentativas para acertar.");

    printf("Tentativa 1\n");
	puts("Adivinhe o numero:");
	scanf("%d", &palpite);

	tentativas = 1;
    while(palpite != numeroCorreto && tentativas < 5 ){
        if (palpite > numeroCorreto){
            puts("Palpite alto!");
        }else{
            puts("Palpite foi baixo!");
        }

        tentativas = tentativas + 1;

        printf("Tentativa %d\n", tentativas);
        printf("Digite seu novo palpite: ");
        scanf("%d", &palpite);
    }
        if(tentativas == 5 && palpite != numeroCorreto){
            printf("Voce errou as 5 tentativas e perdeu o jogo.\n");
        }else{
             puts("Voce ganhou!");
             puts("Fim do jogo.");
        }

	return 0;
}

