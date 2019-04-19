#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

HANDLE hStdout;
int linha = 0;
char LOCAL[500];

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

void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}


int Local() {
    char opcao[50];
    int OPCAO = 0;
    while ((OPCAO > 6) || (OPCAO < 1)) {
        printf("Selecione seu local para leitura de host :\n");
        printf("1)Publico\n2)Monitores\n3)Proprio diretorio\n4)Entrar com o endereco\n5)RM\n6)Sair");
        printf("\n|\n|\n|\n|----->");
        gets(opcao);
        OPCAO = atoi(opcao);
        system("cls");
    }
    LOCAL[0] = '\0';
    switch (OPCAO) {

        case 1:
            strcat(LOCAL, "P:\\TextFile.txt");
            break;
        case 2:
            strcat(LOCAL, "\\\\192.168.60.11\\monitores$\\felipe\\TextFile.txt");
            break;
        case 3:
            strcat(LOCAL, "TextFile.txt");
            break;
        case 4:
            printf("\nDigite o caminho completo para o diretorio :");
            gets(LOCAL);
            strcat(LOCAL, "TextFile.txt");
            break;

        case 5:
            strcat(LOCAL, "F:\\TextFile.txt");
            break;


        case 6:
            exit(2);
    }

}

int main() {
    FILE *leitor;
    Local();

    leitor = fopen(LOCAL, "r");
    while (leitor == NULL) {

        printf("Nao foi possivel ler o host em %s\n", LOCAL);
        system("pause");
        system("cls");
        Local();
        leitor = fopen(LOCAL, "r");

    }
    while (true) {
        char cor, BUFFER[600], lol[123];
        int i = 0;
        wait(1);
        fseek(leitor, 0, SEEK_SET);
        system("cls");
        int numeroo;
        numeroo = 0;
        linha = 0;
        while (!(feof(leitor))) {
            fgets(BUFFER, 300, leitor);
            linha++;
        }


        fseek(leitor, 0, SEEK_SET);

        while (!(feof(leitor))) {


            fgets(BUFFER, 300, leitor);
            numeroo++;

            if (numeroo >= linha - 24) {
                switch (BUFFER[0]) {
                    case '�':
                        COR(6);
                        break;


                    case '�':
                        COR(1);
                        break;


                    case '�':
                        COR(2);
                        break;


                    case '�':
                        COR(3);
                        break;


                    case ';'://MUDAR PARA CYAN NA ESCOLA!!!
                        COR(4);
                        break;


                    case '.'://MUDAR PARA AMARELO NA ESCOLA!!!
                        COR(5);
                        break;

                    default:
                        COR(6);
                        break;
                }
                if (!(feof(leitor))) {
                    for (i = 1; i <= strlen(BUFFER); i++) {
                        printf("%c", BUFFER[i]);
                    }
                }
            }
        }


    }
    fclose(leitor);

}
