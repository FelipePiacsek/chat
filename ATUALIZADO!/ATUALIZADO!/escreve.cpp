#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctime>

HANDLE hStdout;
int escolha = 0;
FILE *leitor;
char LOCAL[500];
char cor = '�';
char letra[1000], nick[5000], oldnick[5000];
bool flag;
char place[100];
char hora[60];

int HORA() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int j, i;
    strcpy(hora, asctime(timeinfo));
    for (i = 11, j = 0; i <= 15, j <= 4; i++, j++)
        hora[j] = hora[i];
    hora[5] = '\0';

}

int COR(int cor) {
    switch (cor) {
        case 6:
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;


        case 1:
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;


        case 2:
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;


        case 3:
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;


        case 4:
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;


        case 5:
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;


        default:
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;


    }

}

bool comando() {
    bool retornar = false;
    if (letra[0] == '\0') {
        retornar = true;
        COR(1);
        printf("SISTEMA : MENSAGEM INVALIDA\n");
        COR(6);
    }
    if (!(strcmp(letra, "/help"))) {
        system("cls");
        printf("Alem de mandar mensagens, voce pode inserir comandos ao programa.\n");
        printf("Aqui segue a lista dos comandos e suas respectivas utilidades :\n\n");
        printf("/help - Exibe esta tela de ajuda.\n");
        printf("/color - Muda a cor que o texto sera lido no le.exe .\n");
        printf("/cls - Limpa a tela .\n");
        printf("/exit - Sai do chat .\n\n");
        retornar = true;
        system("pause");

        system("cls");
    }
    if (!(strcmp(letra, "/cls"))) {
        retornar = true;
        system("cls");
    }
    if (!(strcmp(letra, "/color"))) {
        retornar = true;
        char ESCOLHA[123];
        escolha = 50;
        while ((escolha > 6) || (escolha < 1)) {
            system("cls");
            printf("Escolha sua cor :");

            for (int c = 1; c <= 6; c++) {
                COR(6);
                printf("\n%d) ", c);
                COR(c);
                printf(" ESCOLHA");

            }
            COR(6);
            printf("\n|\n|\n|\n|\n|--->");
            gets(ESCOLHA);
            escolha = atoi(ESCOLHA);
            switch (escolha) {
                case 0:
                    cor = '�';
                    break;
                case 1:
                    cor = '�';
                    break;
                case 2:
                    cor = '�';
                    break;
                case 3:
                    cor = '�';
                    break;
                case 4://MUDAR PARA CYAN NA ESCOLA!!!
                    cor = ';';
                    break;

                case 5://MUDAR PARA CYAN NA ESCOLA!!!
                    cor = '.';
                    break;


            }


        }

        printf("\nCor trocada com sucesso!\n");
        system("pause");
    }
    if (!(strcmp(letra, "/exit"))) {
        HORA();
        fprintf(leitor, " (%s)%s ESTA OFFLINE\n", hora, nick);
        system("taskkill /im le.exe");
        exit(1);
    }
    if (!(strcmp(letra, "/nick"))) {
        strcpy(oldnick, nick);
        printf("\nDigite o seu nick :");
        gets(nick);
        HORA();
        fprintf(leitor, " (%s)%s MUDOU DE NOME PARA %s\n", hora, oldnick, nick);
        retornar = true;
    }

    return (retornar);
}


//     RM 8856
//     alca�uz
int Local() {
    char opcao[50];
    int OPCAO = 0;
    while ((OPCAO > 6) || (OPCAO < 1)) {
        system("cls");
        printf("Selecione seu local para escrita de host :\n");
        printf("1)Publico\n2)Monitores\n3)Proprio diretorio\n4)Entrar com o endereco\n5)RM\n6)Sair");
        printf("\n|\n|\n|\n|----->");
        gets(opcao);
        OPCAO = atoi(opcao);

    }
    LOCAL[0] = '\0';

    switch (OPCAO) {

        case 1:
            strcat(LOCAL, "P:\\TextFile.txt");
            strcpy(place, "Publico");
            break;
        case 2:
            strcat(LOCAL, "\\\\192.168.60.11\\monitores$\\felipe\\TextFile.txt");
            strcpy(place, "Monitores");
            break;
        case 3:
            strcat(LOCAL, "TextFile.txt");
            strcpy(place, "LocalDirectory");
            break;
        case 4:
            printf("\nDigite o caminho completo para o diretorio :");
            gets(LOCAL);
            strcat(LOCAL, "TextFile.txt");
            strcpy(place, "AreaUnknown");
            break;

        case 5:
            strcat(LOCAL, "F:\\TextFile.txt");
            strcpy(place, "RM");
            break;


        case 6:
            exit(2);
    }

}

int main() {
    while (true) {
        Local();
        leitor = fopen(LOCAL, "at");
        if (leitor == NULL) {
            printf("Falha ao abrir o arquivo, tente novamente...\n");
            system("pause");
            system("cls");
        } else
            break;
    }
    fclose(leitor);
    printf("Digite o seu nick :");
    gets(nick);

    printf("Bem vindo %s!\n", nick);
    system("pause");
    system("cls");
    while (true) {

        leitor = fopen(LOCAL, "at");
        printf("Chat\\%s\\", place);
        COR(escolha);
        printf("%s", nick);
        COR(6);
        printf(">");
        gets(letra);

        flag = comando();
        strcat(letra, "\n");
        if (flag == false) {
            HORA();

            fputc(cor, leitor);
            fprintf(leitor, "(%s)", hora);
            fputs(nick, leitor);
            fprintf(leitor, " diz : ");

            fputs(letra, leitor);
        }
        fclose(leitor);
    }
}
 
