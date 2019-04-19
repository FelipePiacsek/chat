#include "../lib/System.h"

/*
This should write messages on screen.
Date :31/10/2010
Time :18:36
*/
char Nick[50];
char Mensagem[300];
char hora[50];
char buscapalavra[200], search[200];
FILE *Writer;
int i, j, chao, teto;
char PegaEncriptado[300];
char Passar[300];

void Busca() {
    PegaEncriptado[0] = '\0';
    bool existe = false;
    search[0] = '\0';
    FILE *Searcher = fopen(LOCAL, "r");
    printf("Digite a palavra/frase a ser encontrada :");
    gets(buscapalavra);
    chao = 0;
    int count = 0, numberofwords = 0, linhas = 0;
    teto = strlen(buscapalavra);
    while (!(feof(Searcher))) {
        search[0] = PegaEncriptado[0] = '\0';
        fgets(PegaEncriptado, 290, Searcher);
        strcat(search, Encript(PegaEncriptado, 1));
        linhas++;
        if (LineCounter() >= linhas) {
            chao = count = 0;
            teto = strlen(buscapalavra) - 1;
            while (count < strlen(search)) {
                j = 0;
                for (i = chao; i <= teto; i++) {
                    if (buscapalavra[j] == search[i]) existe = true;
                    else {
                        existe = false;
                        break;
                    }
                    j++;
                }
                chao++;
                teto++;
                if (existe == true) {
                    printf("%s\n", search);
                    numberofwords++;
                    break;
                }
                count++;
            }
        }
    }
    fclose(Searcher);
    printf("\nA busca por \"%s\" retornou %d linhas com resultados.\n", buscapalavra, numberofwords);
}

int Comand() {
    bool ReturnValue = 0;
    if (!(strcmp(Mensagem, "/exit"))) {
        system("taskkill /f /im read.exe");
        Passar[0] = '\0';
        strcat(Passar, "(");
        strcat(Passar, hora);
        strcat(Passar, ")");
        strcat(Passar, "  ");
        strcat(Passar, Nick);
        strcat(Passar, " ESTA OFFLINE.\n");
        fprintf(Writer, "%s", Encript(Passar, 0));
        exit(1);
    }
    if (!(strcmp(Mensagem, "/nick"))) {
        printf("Digite o seu novo nick :");
        gets(Nick);
        ReturnValue = 1;
    }
    if (!(strcmp(Mensagem, "/help"))) {
        system("cls");
        printf("Digite /exit para sair.\nDigite /nick para mudar o seu nick.\nDigite /cls para limpar a tela de escrita.\nDigite /busca para buscar algo na conversa.\n");
        ReturnValue = 1;
    }
    if (!(strcmp(Mensagem, "/cls"))) {
        system("cls");
        ReturnValue = 1;
    }
    if (!(strcmp(Mensagem, "/busca"))) {
        system("cls");
        Busca();
        ReturnValue = 1;
    }
    return (ReturnValue);
}

int main(int argc, char *argv[]) {


    if (strcmp(GetPassword(""), "obvia!")) {
        system("cls");
        printf("PassWord Incorrect. Program will exit.\n");
        system("pause");
        exit(2);
    }
    Local();
    Writer = fopen(LOCAL, "at");

    while (Writer == NULL) {
        printf("Nao foi possivel abrir o arquivo em %s.\n", LOCAL);
        system("pause");
        system("cls");
        Local();
        Writer = fopen(LOCAL, "at");
    }
    fclose(Writer);

    printf("Digite o seu Nick :");
    gets(Nick);
    printf("\nSeja bem vindo %s!\n", Nick);
    system("pause");
    system("cls");
    hora[0] = '\0';

    while (1) {
        Passar[0] = '\0';
        printf("Chat/%s>", Nick);
        gets(Mensagem);
        Writer = fopen(LOCAL, "at");
        strcat(hora, HORA());
        strcat(Passar, "(");
        strcat(Passar, hora);
        strcat(Passar, ")");
        strcat(Passar, "  ");
        strcat(Passar, Nick);
        strcat(Passar, " diz :");
        strcat(Passar, Mensagem);
        if (Comand() == 0) {
            fprintf(Writer, "%s\n", Encript(Passar, 0));
        }
        hora[0] = '\0';
        fclose(Writer);

    }
}
