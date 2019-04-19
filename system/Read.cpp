#include "../lib/System.h"
/*
This should display messages of people using the chat.
Date :31/10/2010
Time :17:32
*/


int main (int argc, char* argv[])
{
if (strcmp(GetPassword(""),"obvia!")) { system ("cls"); printf("PassWord Incorrect. Program will exit.\n"); system("pause"); exit(2); }
Local();
FILE *Reader=fopen(LOCAL,"r");
while (Reader==NULL)
{
     printf("Nao foi possivel ler o host em %s\n",LOCAL);
     system("pause");
     system("cls");
     Local();
     Reader=fopen(LOCAL,"r");
}

int Linhas=0;
while (1)
{

    if (LineCounter() > Linhas)
    {
    WriteOnScreen(Linhas);
    Linhas=LineCounter();
    }
}



}


