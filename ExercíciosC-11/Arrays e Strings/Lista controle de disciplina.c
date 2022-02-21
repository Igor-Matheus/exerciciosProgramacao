/**
 * Aluno / Autor: Igor Matheus Medeiros Brito
 * Matr�cula: 20200002989
 * Nome: Lista controle de disciplina.c
 * Descri��o: Um programa que funciona como um controle de uma
 * disciplina. Ele gera uma lista com a situa��o de todos os
 * alunos, com suas notas, m�dias finais e dizendo se o aluno
 * foi aprovado ou reprovado.
 */

#include <stdio.h>
#include "stdlib.h" //Essas duas bibliotecas foram adicionadas j� que
#include "string.h" //o programa vai precisar trabalhar com strings.

#define MAX_DISCIPLINA 51 //As constantes simb�licas foram usadas para os tamanhos dos Arrays do tipo "char" no programa.
#define MAX_NOME 31 //Tamanho 51 porque o n�mero m�ximo de caracteres para a disciplina � 50, mas tem que ter espa�o para o '\0'.
//Tamanho 31 porque o n�mero m�ximo de caracteres para o nome � 30, mas tem que ter espa�o para o '\0'.

int main(void){
    int numeroDeAlunos, i; //Vari�veis inteiras para, respectivamente, a quantidade de alunos e o contador para uso nos "for's".
    char disciplina[MAX_DISCIPLINA]; //Array de caracteres para receber o nome da disciplina.

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

    int matricula[numeroDeAlunos];//Um Array do tipo int para as matr�culas e um bidimensional do tipo char (Array de strings)
    char nome[numeroDeAlunos][MAX_NOME];//para os nomes dos alunos. Foram definidos aqui pois necessitam do valor da vari�vel
    //"numeroDeAlunos" definida primeiro para os seus tamanhos. O "[MAX_NOME]" � o limite de caracteres de cada nome.

    /*La�o de repeti��o "for" garante que as matr�culas e os nomes dos alunos sejam perguntados e recebidos. O "i", al�m de
    contador tamb�m acaba sendo usado para funcionar como indice dos arrays que est�o sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual sua matricula, aluno(a) #%d? ", i+1);//Pergunta a matr�cula dos alunos.
        scanf("%d%*c", &matricula[i]);//scanf recebe a matr�cula de cada aluno. O "%*c" para o que restar n�o atrapalhar
        //na pr�xima leitura, que no caso � a do fgets que vem a seguir.

        printf("Qual seu nome, aluno(a) #%d (no maximo %d caracteres)? ", i+1, MAX_NOME-1);
        fgets(nome[i], MAX_NOME, stdin);//O printf pergunta o nome e diz o m�ximo de caracteres que o mesmo pode ter.
        //O fgets recebe o nome dos alunos via teclado.

        //Atrav�s desse desvio condicional "if", o '\n' que aparece ao pressionar enter depois de escrever o nome �
        if (nome[i][strlen(nome[i])-1] == '\n'){//"substitu�do" por '\0'. Assim, n�o fica mais o '\n' depois do enter,
                                                //e o ultimo caractere n�o aparece na linha de baixo.
            nome[i][strlen(nome[i])-1] = '\0';
        /*A fun��o "strlen" diz o comprimento da string e o "-1" � para analisar se o caractere antes do '\0' � '\n'. Se for,
        esse '\n' agora passar� a ser o '\0', "eliminando" assim o '\n' da string.*/

        }
    }

    float nota1[numeroDeAlunos], nota2[numeroDeAlunos];//Definidos dois Arrays do tipo int para receber a primeira e a segunda
    printf("\n");//nota de cada aluno. O printf em seguida com o '\n' foi apenas para pular uma linha para a pergunta a seguir.

    /*La�o de repeti��o "for" garante que as notas dos alunos sejam perguntadas e recebidas. O "i", al�m de
    contador tamb�m acaba sendo usado para funcionar como indice dos arrays que est�o sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("Qual o valor das suas duas notas %s? ", nome[i]);//"O "%s" e o "nome[i]" para que na pergunta apare�a
                                                                 //o nome do aluno

        scanf("%f %f%*c", &nota1[i], &nota2[i]);//scanf recebe as notas de cada aluno. O "%*c" para o que restar n�o atrapalhar
        //na pr�xima leitura.
    }

    /*Impress�o do "cabe�alho da lista". Os puts e printf imprimem na tela a lista com  o cabe�alho primeiro: disiciplina,
    matr�cula, nome, nota 1, nota 2 e situa��o.*/
    puts("\n*********************************************** Lista elaborada ***********************************************");

    printf("\nDisciplina: %s\n", disciplina);//O "%s" imprime o nome da disciplina.
    puts("==================================================================================================================");

    puts("Matricula\tNome\t\t\t\t\tNota 1\t\tNota 2\t\tMedia\t\tSituacao");
    puts("==================================================================================================================");

    /*La�o de repeti��o "for" garante que todos os resultados do programa sejam impressos por meio
    dos printfs.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("%05d\t\t%-30s\t\t", matricula[i], nome[i]);//Imprime a matr�cula e o nome, alinhados ao cabe�alho.
        printf("%.1f\t\t%.1f\t\t%.1f", nota1[i], nota2[i], (nota1[i] + nota2[i])/2);//Imprime as notas e a m�dia, alinhados.
        printf("\t\t%s\n", ((nota1[i] + nota2[i])/2 >= 7.0) ? "Aprovado" : "Reprovado");
        /*Imprime a "Situacao" na lista, com o operador condicional dizendo que "se a m�dia for maior ou igual a sete, coloca-se
        a palavra 'Aprovado' e, se for menor que sete, coloca-se a palavra 'Reprovado'.*/
    }

    return 0;
}
