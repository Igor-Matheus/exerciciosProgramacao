/**
 * Aluno / Autor: Igor Matheus Medeiros Brito
 * Matrícula: 20200002989
 * Nome: Lista controle de disciplina.c
 * Descrição: Um programa que funciona como um controle de uma
 * disciplina. Ele gera uma lista com a situação de todos os
 * alunos, com suas notas, médias finais e dizendo se o aluno
 * foi aprovado ou reprovado.
 */

#include <stdio.h>
#include "stdlib.h" //Essas duas bibliotecas foram adicionadas já que
#include "string.h" //o programa vai precisar trabalhar com strings.

#define MAX_DISCIPLINA 51 //As constantes simbólicas foram usadas para os tamanhos dos Arrays do tipo "char" no programa.
#define MAX_NOME 31 //Tamanho 51 porque o número máximo de caracteres para a disciplina é 50, mas tem que ter espaço para o '\0'.
//Tamanho 31 porque o número máximo de caracteres para o nome é 30, mas tem que ter espaço para o '\0'.

int main(void){
    int numeroDeAlunos, i; //Variáveis inteiras para, respectivamente, a quantidade de alunos e o contador para uso nos "for's".
    char disciplina[MAX_DISCIPLINA]; //Array de caracteres para receber o nome da disciplina.

    puts("************************************************ Boas Vindas! ************************************************");
    printf("\nVamos elaborar o controle de uma disciplina que vai gerar uma lista, mostrando\n");
    printf("as notas e medias finais de todos os alunos.\n"); //Apresentação do programa ao usuário.

    printf("\nQual o nome da disciplina (no maximo %d caracteres)? ", MAX_DISCIPLINA-1); //Mostrando ao usuário o limite de
                                                                                         //caracteres.

    fgets(disciplina, MAX_DISCIPLINA, stdin);//O printf pergunta o nome da disciplina e, como se trata de um Array de caracteres,
    //utilizou-se o fgets para receber esse nome via teclado.

    //Através desse desvio condicional "if", o '\n' que aparece ao pressionar enter depois de escrever a disciplina é
    if (disciplina[strlen(disciplina)-1] == '\n'){//"substituído" por '\0'. Assim, não fica mais o '\n' depois do enter,
                                                  //e o ultimo caractere não aparece na linha de baixo.
        disciplina[strlen(disciplina)-1] = '\0';
    /*A função "strlen" diz o comprimento da string e o "-1" é para analisar se o caractere antes do '\0' é '\n'. Se for,
    esse '\n' agora passará a ser o '\0', "eliminando" assim o '\n' da string.*/

    }

    printf("Qual a quantidade de alunos (no maximo 30)? ");//Pergunta a quantidade de alunos, mostrando o limite da mesma.
    scanf("%d", &numeroDeAlunos);//scanf recebe do usuário um número inteiro que diz a quantidade de alunos.

    int matricula[numeroDeAlunos];//Um Array do tipo int para as matrículas e um bidimensional do tipo char (Array de strings)
    char nome[numeroDeAlunos][MAX_NOME];//para os nomes dos alunos. Foram definidos aqui pois necessitam do valor da variável
    //"numeroDeAlunos" definida primeiro para os seus tamanhos. O "[MAX_NOME]" é o limite de caracteres de cada nome.

    /*Laço de repetição "for" garante que as matrículas e os nomes dos alunos sejam perguntados e recebidos. O "i", além de
    contador também acaba sendo usado para funcionar como indice dos arrays que estão sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual sua matricula, aluno(a) #%d? ", i+1);//Pergunta a matrícula dos alunos.
        scanf("%d%*c", &matricula[i]);//scanf recebe a matrícula de cada aluno. O "%*c" para o que restar não atrapalhar
        //na próxima leitura, que no caso é a do fgets que vem a seguir.

        printf("Qual seu nome, aluno(a) #%d (no maximo %d caracteres)? ", i+1, MAX_NOME-1);
        fgets(nome[i], MAX_NOME, stdin);//O printf pergunta o nome e diz o máximo de caracteres que o mesmo pode ter.
        //O fgets recebe o nome dos alunos via teclado.

        //Através desse desvio condicional "if", o '\n' que aparece ao pressionar enter depois de escrever o nome é
        if (nome[i][strlen(nome[i])-1] == '\n'){//"substituído" por '\0'. Assim, não fica mais o '\n' depois do enter,
                                                //e o ultimo caractere não aparece na linha de baixo.
            nome[i][strlen(nome[i])-1] = '\0';
        /*A função "strlen" diz o comprimento da string e o "-1" é para analisar se o caractere antes do '\0' é '\n'. Se for,
        esse '\n' agora passará a ser o '\0', "eliminando" assim o '\n' da string.*/

        }
    }

    float nota1[numeroDeAlunos], nota2[numeroDeAlunos];//Definidos dois Arrays do tipo int para receber a primeira e a segunda
    printf("\n");//nota de cada aluno. O printf em seguida com o '\n' foi apenas para pular uma linha para a pergunta a seguir.

    /*Laço de repetição "for" garante que as notas dos alunos sejam perguntadas e recebidas. O "i", além de
    contador também acaba sendo usado para funcionar como indice dos arrays que estão sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("Qual o valor das suas duas notas %s? ", nome[i]);//"O "%s" e o "nome[i]" para que na pergunta apareça
                                                                 //o nome do aluno

        scanf("%f %f%*c", &nota1[i], &nota2[i]);//scanf recebe as notas de cada aluno. O "%*c" para o que restar não atrapalhar
        //na próxima leitura.
    }

    /*Impressão do "cabeçalho da lista". Os puts e printf imprimem na tela a lista com  o cabeçalho primeiro: disiciplina,
    matrícula, nome, nota 1, nota 2 e situação.*/
    puts("\n*********************************************** Lista elaborada ***********************************************");

    printf("\nDisciplina: %s\n", disciplina);//O "%s" imprime o nome da disciplina.
    puts("==================================================================================================================");

    puts("Matricula\tNome\t\t\t\t\tNota 1\t\tNota 2\t\tMedia\t\tSituacao");
    puts("==================================================================================================================");

    /*Laço de repetição "for" garante que todos os resultados do programa sejam impressos por meio
    dos printfs.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("%05d\t\t%-30s\t\t", matricula[i], nome[i]);//Imprime a matrícula e o nome, alinhados ao cabeçalho.
        printf("%.1f\t\t%.1f\t\t%.1f", nota1[i], nota2[i], (nota1[i] + nota2[i])/2);//Imprime as notas e a média, alinhados.
        printf("\t\t%s\n", ((nota1[i] + nota2[i])/2 >= 7.0) ? "Aprovado" : "Reprovado");
        /*Imprime a "Situacao" na lista, com o operador condicional dizendo que "se a média for maior ou igual a sete, coloca-se
        a palavra 'Aprovado' e, se for menor que sete, coloca-se a palavra 'Reprovado'.*/
    }

    return 0;
}
