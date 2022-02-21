#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, tentativas, numeroCorreto;

    srand(time(NULL));
    numeroCorreto = rand() % 100;
	puts("Bem-vindo!");

	puts("Adivinhe o numero:");
	scanf("%d", &palpite);

    tentativas = 0;
    while(palpite != numeroCorreto){
        if (palpite > numeroCorreto){
            puts("Palpite alto!");
        }else{
            puts("Palpite foi baixo!");
        }

        tentativas = tentativas + 1;
        printf("Digite seu novo palpite: ");
        scanf("%d", &palpite);
    }

    puts("Voce ganhou!");
	puts("Fim do jogo.");
	printf("Foram feitos %d palpites ate acertar.\n", tentativas);

	return 0;
}

