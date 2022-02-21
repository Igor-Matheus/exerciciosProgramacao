/**
 * Aluno / Autor: Igor Matheus Medeiros Brito
 * Matr�cula: 20200002989
 * Nome: Lista controle de disciplina 2.0.c
 * Descri��o: Um programa que funciona como um controle de uma
 * disciplina. Ele gera uma lista com a situa��o de todos os
 * alunos, com suas notas, m�dias finais e dizendo se o aluno
 * foi aprovado ou reprovado.
 */

#include <stdio.h>
#include "stdlib.h" //Essas duas bibliotecas foram adicionadas j� que
#include "string.h" //o programa vai precisar trabalhar com strings.

#define MAX_DISCIPLINA 51 //As constantes simb�licas foram usadas para os tamanhos dos Arrays do tipo "char" no programa.
#define MAX_NOME 41 //Tamanho 51 porque o n�mero m�ximo de caracteres para a disciplina � 50, mas tem que ter espa�o para o '\0'.
//Tamanho 41 porque o n�mero m�ximo de caracteres para o nome � 40, mas tem que ter espa�o para o '\0'.

/*Criando o tipo "tDados" para a vari�vel estruturada "informacao" que ser� definida mais abaixo e funcionar� como um array de
estruturas, ou seja, cada elemento ter� toda essa estrutura.*/
typedef struct {
           int matricula; //Vari�vel inteira para a matr�cula.
           char nome[MAX_NOME]; //Campo com um array do tipo "char" para armazenar o nome de cada aluno.
           float nota1, nota2, nota3;//Essas vari�veis do tipo "float" armazenam cada uma das 3 notas de cada aluno.
           float notaRecuperacao;//Vari�vel para a nota de recupera��o, caso o aluno tenha ficado em recupera��o.
        } tDados; //Nome do tipo.

float Media(tDados *informacao){ //Fun��o que calcula a m�dia aritm�tica das 3 notas de cada aluno, recebendo um ponteiro para a
                                 //vari�vel estruturada.

    return (informacao->nota1 + informacao->nota2 + informacao->nota3) / 3; //Se tratando de ponteiros, os campos s�o acessados
                                                                            //com "setas" e n�o com "pontos". Retorna a m�dia.
}

float MediaFinal(tDados *informacao){//Fun��o que, recebendo um ponteiro para vari�vel estruturada, calcula a m�dia final para
                                     //os alunos que ficaram em recupera��o.

    float mediaInicial, mediaFinal; //Vari�veis definidas apenas para receber o valor das express�es e deixar o programa mais
                                    //leg�vel.

    mediaInicial = (informacao->nota1 + informacao->nota2 + informacao->nota3) / 3;//C�lculo da m�dia aritm�tica.

    mediaFinal = ((mediaInicial * 6) + (informacao->notaRecuperacao * 4)) / 10;//F�rmula para m�dia final, depois da recupera��o.

    return mediaFinal;//Retorna a m�dia final.
}

int main(void){
    int i, j, numeroDeAlunos; //Vari�veis inteiras para, respectivamente, contadores do "for" e a quantidade de alunos.
    char disciplina[MAX_DISCIPLINA];//Array de caracteres para armazenar o nome da disciplina.

    puts("************************************************ Boas Vindas! ************************************************");
    printf("\nVamos elaborar o controle de uma disciplina que vai gerar uma lista, mostrando\n");
    printf("as notas e medias finais de todos os alunos.\n"); //Apresenta��o do programa ao usu�rio.

    printf("\nQual o nome da disciplina (no maximo %d caracteres)? ", MAX_DISCIPLINA-1); //Mostrando ao usu�rio o limite de
                                                                                         //caracteres.

    fgets(disciplina, MAX_DISCIPLINA, stdin);//O printf pergunta o nome da disciplina e, como se trata de um Array de caracteres,
    //utilizou-se o fgets para receber esse nome via teclado.

    //Atrav�s desse desvio condicional "if", o '\n' que aparece ao pressionar enter depois de escrever a disciplina �
    if (disciplina[strlen(disciplina)-1] == '\n'){//"substitu�do" por '\0'. Assim, n�o fica mais o '\n' depois do enter,
                                                  //e o ultimo caractere n�o aparece na linha de baixo.
        disciplina[strlen(disciplina)-1] = '\0';
    /*A fun��o "strlen" diz o comprimento da string e o "-1" � para analisar se o caractere antes do '\0' � '\n'. Se for,
    esse '\n' agora passar� a ser o '\0', "eliminando" assim o '\n' da string.*/

    }

    printf("Qual a quantidade de alunos (no maximo 30)? ");//Pergunta a quantidade de alunos, mostrando o limite da mesma.
    scanf("%d", &numeroDeAlunos);//scanf recebe do usu�rio um n�mero inteiro que diz a quantidade de alunos.

    tDados informacao[numeroDeAlunos]; //Foi definido somente agora o array de estruturas, do tipo "tDados", pois era necess�rio
    //primeiro ter o valor de "numeroDeAlunos" para ser o tamanho do array de estruturas.

    /*La�o de repeti��o "for" garante que as matr�culas e os nomes dos alunos sejam perguntados e recebidos. O "i", al�m de
    contador, tamb�m acaba sendo usado para funcionar como indice do array de estruturas que est� sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual sua matricula, aluno(a) #%d? ", i+1);//Pergunta a matr�cula dos alunos.
        scanf("%d%*c", &informacao[i].matricula);//scanf recebe a matr�cula de cada aluno. O "%*c" para o que restar n�o
        //atrapalhar na pr�xima leitura, que no caso � a do fgets que vem a seguir.

        printf("Qual seu nome, aluno(a) #%d (no maximo %d caracteres)? ", i+1, MAX_NOME-1);
        fgets(informacao[i].nome, MAX_NOME, stdin);//O printf pergunta o nome e diz o m�ximo de caracteres que o mesmo pode ter.
        //O fgets recebe o nome dos alunos via teclado.

        //Atrav�s desse desvio condicional "if", o '\n' que aparece ao pressionar enter depois de escrever o nome �
        if (informacao[i].nome[strlen(informacao[i].nome)-1] == '\n'){//"substitu�do" por '\0'. Assim, n�o fica mais o '\n'
                                                //depois do enter, e o ultimo caractere n�o aparece na linha de baixo.

            informacao[i].nome[strlen(informacao[i].nome)-1] = '\0';
        /*A fun��o "strlen" diz o comprimento da string e o "-1" � para analisar se o caractere antes do '\0' � '\n'. Se for,
        esse '\n' agora passar� a ser o '\0', "eliminando" assim o '\n' da string.*/

        }
    }

    /*La�o de repeti��o "for" garante que as notas dos alunos sejam perguntadas e recebidas. O "i", al�m de
    contador tamb�m acaba sendo usado para funcionar como indice dos arrays que est�o sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual o valor das suas 3 notas, %s? ", informacao[i].nome);//"O "%s" e o "informacao[i].nome" para que na pergunta
                                                                         //apare�a o nome do aluno.

        scanf("%f %f %f%*c", &informacao[i].nota1, &informacao[i].nota2, &informacao[i].nota3);
        //scanf recebe as notas de cada aluno. O "%*c" para o que restar n�o atrapalhar na pr�xima leitura.

        /*Se a m�dia for maior ou igual a 4 e menor que sete, o aluno ficou em recupera��o. Ent�o, o programa vai perguntar e ler
        a nota de recupera��o do aluno.*/
        if (Media(&informacao[i]) >= 4 && Media(&informacao[i]) < 7){
            printf("\n%s, sua media atual eh %.1f. Qual sua nota na recuperacao? ", informacao[i].nome, Media(&informacao[i]));
            //printf informa o nome do aluno e sua m�dia atual.Depois, pergunta a nota de recupera��o.

            scanf("%f%*c", &informacao[i].notaRecuperacao);
            //scanf recebe a nota de recupera��o de cada aluno. O "%*c" para o que restar n�o atrapalhar na pr�xima leitura.

        }
    }


    /*Impress�o do "cabe�alho da lista". Os puts e printf imprimem na tela a lista com  o cabe�alho primeiro: disiciplina,
    matr�cula, nome, nota 1, nota 2 e situa��o.*/
    puts("\n*********************************************** Lista elaborada ***********************************************");

    printf("\nDisciplina: %s\n", disciplina);//O "%s" imprime o nome da disciplina.
    puts("==========================================================================================================");

    puts("Matricula\tNome\t\t\t\t\tNota1\tNota2\tNota3\tRec\tMedia\tSituacao");
    puts("==========================================================================================================");

    /*La�o de repeti��o "for" garante que todos os resultados do programa sejam impressos por meio
    dos printfs.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("%05d\t\t%-40s", informacao[i].matricula, informacao[i].nome);//Imprime a matr�cula e o nome, alinhados ao
                                                                             //cabe�alho.

        printf("%.1f\t%.1f\t%.1f", informacao[i].nota1, informacao[i].nota2, informacao[i].nota3);//Imprime as 3 notas,
                                                                                                  //alinhadas.

        /*Se a m�dia for maior ou igual a 4 e menor que sete: o aluno ficou em recupera��o e a nota da recupera��o � impressa,
        seguida pela m�dia final, calculada pela fun��o "MediaFinal", e � impressa tamb�m a situa��o do aluno. Se a media final
        for maior ou igual a 5, imprime "Aprovado", se n�o, imprime "Reprovado".*/
        if (Media(&informacao[i]) >= 4 && Media(&informacao[i]) < 7){
            printf("\t%.1f", informacao[i].notaRecuperacao);
            printf("\t%.1f", MediaFinal(&informacao[i]));
            printf("\t%s\n", (MediaFinal(&informacao[i]) >= 5) ? "Aprovado" : "Reprovado");

        /*Se n�o entrou na condi��o, ent�o o aluno n�o ficou em recupera��o e, em vez disso, imprime-se: um tra�o para ficar no
        espa�o "Rec" da tabela (j� que n�o precisou de recupera��o); depois a media do aluno, calculada pela fun��o "Media"; e,
        por �ltimo, a situa��o: se a m�dia for maior ou igual a sete, imprime "Aprovado", caso contr�rio, "Reprovado".*/
        }else{
            printf("\t%s", " - ");
            printf("\t%.1f", Media(&informacao[i]));
            printf("\t%s\n", (Media(&informacao[i]) >= 7) ? "Aprovado" : "Reprovado");
        }

    }

    return 0;
}
