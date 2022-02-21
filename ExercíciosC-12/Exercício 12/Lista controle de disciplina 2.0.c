/**
 * Aluno / Autor: Igor Matheus Medeiros Brito
 * Matrícula: 20200002989
 * Nome: Lista controle de disciplina 2.0.c
 * Descrição: Um programa que funciona como um controle de uma
 * disciplina. Ele gera uma lista com a situação de todos os
 * alunos, com suas notas, médias finais e dizendo se o aluno
 * foi aprovado ou reprovado.
 */

#include <stdio.h>
#include "stdlib.h" //Essas duas bibliotecas foram adicionadas já que
#include "string.h" //o programa vai precisar trabalhar com strings.

#define MAX_DISCIPLINA 51 //As constantes simbólicas foram usadas para os tamanhos dos Arrays do tipo "char" no programa.
#define MAX_NOME 41 //Tamanho 51 porque o número máximo de caracteres para a disciplina é 50, mas tem que ter espaço para o '\0'.
//Tamanho 41 porque o número máximo de caracteres para o nome é 40, mas tem que ter espaço para o '\0'.

/*Criando o tipo "tDados" para a variável estruturada "informacao" que será definida mais abaixo e funcionará como um array de
estruturas, ou seja, cada elemento terá toda essa estrutura.*/
typedef struct {
           int matricula; //Variável inteira para a matrícula.
           char nome[MAX_NOME]; //Campo com um array do tipo "char" para armazenar o nome de cada aluno.
           float nota1, nota2, nota3;//Essas variáveis do tipo "float" armazenam cada uma das 3 notas de cada aluno.
           float notaRecuperacao;//Variável para a nota de recuperação, caso o aluno tenha ficado em recuperação.
        } tDados; //Nome do tipo.

float Media(tDados *informacao){ //Função que calcula a média aritmética das 3 notas de cada aluno, recebendo um ponteiro para a
                                 //variável estruturada.

    return (informacao->nota1 + informacao->nota2 + informacao->nota3) / 3; //Se tratando de ponteiros, os campos são acessados
                                                                            //com "setas" e não com "pontos". Retorna a média.
}

float MediaFinal(tDados *informacao){//Função que, recebendo um ponteiro para variável estruturada, calcula a média final para
                                     //os alunos que ficaram em recuperação.

    float mediaInicial, mediaFinal; //Variáveis definidas apenas para receber o valor das expressões e deixar o programa mais
                                    //legível.

    mediaInicial = (informacao->nota1 + informacao->nota2 + informacao->nota3) / 3;//Cálculo da média aritmética.

    mediaFinal = ((mediaInicial * 6) + (informacao->notaRecuperacao * 4)) / 10;//Fórmula para média final, depois da recuperação.

    return mediaFinal;//Retorna a média final.
}

int main(void){
    int i, j, numeroDeAlunos; //Variáveis inteiras para, respectivamente, contadores do "for" e a quantidade de alunos.
    char disciplina[MAX_DISCIPLINA];//Array de caracteres para armazenar o nome da disciplina.

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

    tDados informacao[numeroDeAlunos]; //Foi definido somente agora o array de estruturas, do tipo "tDados", pois era necessário
    //primeiro ter o valor de "numeroDeAlunos" para ser o tamanho do array de estruturas.

    /*Laço de repetição "for" garante que as matrículas e os nomes dos alunos sejam perguntados e recebidos. O "i", além de
    contador, também acaba sendo usado para funcionar como indice do array de estruturas que está sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual sua matricula, aluno(a) #%d? ", i+1);//Pergunta a matrícula dos alunos.
        scanf("%d%*c", &informacao[i].matricula);//scanf recebe a matrícula de cada aluno. O "%*c" para o que restar não
        //atrapalhar na próxima leitura, que no caso é a do fgets que vem a seguir.

        printf("Qual seu nome, aluno(a) #%d (no maximo %d caracteres)? ", i+1, MAX_NOME-1);
        fgets(informacao[i].nome, MAX_NOME, stdin);//O printf pergunta o nome e diz o máximo de caracteres que o mesmo pode ter.
        //O fgets recebe o nome dos alunos via teclado.

        //Através desse desvio condicional "if", o '\n' que aparece ao pressionar enter depois de escrever o nome é
        if (informacao[i].nome[strlen(informacao[i].nome)-1] == '\n'){//"substituído" por '\0'. Assim, não fica mais o '\n'
                                                //depois do enter, e o ultimo caractere não aparece na linha de baixo.

            informacao[i].nome[strlen(informacao[i].nome)-1] = '\0';
        /*A função "strlen" diz o comprimento da string e o "-1" é para analisar se o caractere antes do '\0' é '\n'. Se for,
        esse '\n' agora passará a ser o '\0', "eliminando" assim o '\n' da string.*/

        }
    }

    /*Laço de repetição "for" garante que as notas dos alunos sejam perguntadas e recebidas. O "i", além de
    contador também acaba sendo usado para funcionar como indice dos arrays que estão sendo recebidos.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual o valor das suas 3 notas, %s? ", informacao[i].nome);//"O "%s" e o "informacao[i].nome" para que na pergunta
                                                                         //apareça o nome do aluno.

        scanf("%f %f %f%*c", &informacao[i].nota1, &informacao[i].nota2, &informacao[i].nota3);
        //scanf recebe as notas de cada aluno. O "%*c" para o que restar não atrapalhar na próxima leitura.

        /*Se a média for maior ou igual a 4 e menor que sete, o aluno ficou em recuperação. Então, o programa vai perguntar e ler
        a nota de recuperação do aluno.*/
        if (Media(&informacao[i]) >= 4 && Media(&informacao[i]) < 7){
            printf("\n%s, sua media atual eh %.1f. Qual sua nota na recuperacao? ", informacao[i].nome, Media(&informacao[i]));
            //printf informa o nome do aluno e sua média atual.Depois, pergunta a nota de recuperação.

            scanf("%f%*c", &informacao[i].notaRecuperacao);
            //scanf recebe a nota de recuperação de cada aluno. O "%*c" para o que restar não atrapalhar na próxima leitura.

        }
    }


    /*Impressão do "cabeçalho da lista". Os puts e printf imprimem na tela a lista com  o cabeçalho primeiro: disiciplina,
    matrícula, nome, nota 1, nota 2 e situação.*/
    puts("\n*********************************************** Lista elaborada ***********************************************");

    printf("\nDisciplina: %s\n", disciplina);//O "%s" imprime o nome da disciplina.
    puts("==========================================================================================================");

    puts("Matricula\tNome\t\t\t\t\tNota1\tNota2\tNota3\tRec\tMedia\tSituacao");
    puts("==========================================================================================================");

    /*Laço de repetição "for" garante que todos os resultados do programa sejam impressos por meio
    dos printfs.*/
    for(i = 0; i < numeroDeAlunos; i++){
        printf("%05d\t\t%-40s", informacao[i].matricula, informacao[i].nome);//Imprime a matrícula e o nome, alinhados ao
                                                                             //cabeçalho.

        printf("%.1f\t%.1f\t%.1f", informacao[i].nota1, informacao[i].nota2, informacao[i].nota3);//Imprime as 3 notas,
                                                                                                  //alinhadas.

        /*Se a média for maior ou igual a 4 e menor que sete: o aluno ficou em recuperação e a nota da recuperação é impressa,
        seguida pela média final, calculada pela função "MediaFinal", e é impressa também a situação do aluno. Se a media final
        for maior ou igual a 5, imprime "Aprovado", se não, imprime "Reprovado".*/
        if (Media(&informacao[i]) >= 4 && Media(&informacao[i]) < 7){
            printf("\t%.1f", informacao[i].notaRecuperacao);
            printf("\t%.1f", MediaFinal(&informacao[i]));
            printf("\t%s\n", (MediaFinal(&informacao[i]) >= 5) ? "Aprovado" : "Reprovado");

        /*Se não entrou na condição, então o aluno não ficou em recuperação e, em vez disso, imprime-se: um traço para ficar no
        espaço "Rec" da tabela (já que não precisou de recuperação); depois a media do aluno, calculada pela função "Media"; e,
        por último, a situação: se a média for maior ou igual a sete, imprime "Aprovado", caso contrário, "Reprovado".*/
        }else{
            printf("\t%s", " - ");
            printf("\t%.1f", Media(&informacao[i]));
            printf("\t%s\n", (Media(&informacao[i]) >= 7) ? "Aprovado" : "Reprovado");
        }

    }

    return 0;
}
