void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

char opcao[50], LOCAL[100];

void Local() {
    LOCAL[0] = '\0';
    opcao[0] = '\0';
    while ((atoi(opcao) > 6) || (atoi(opcao) < 1)) {
        printf("Selecione seu local para leitura de host :\n");
        printf("1)Publico\n2)Monitores\n3)Proprio diretorio\n4)Entrar com o endereco\n5)RM\n6)Sair");
        printf("\n|\n|\n|\n|----->");
        gets(opcao);
        system("cls");
    }
    switch (atoi(opcao)) {
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
            break;
    }
}

char *HORA() {
    char hora[60];
    hora[0] = '\0';
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int j, i;
    strcpy(hora, asctime(timeinfo));
    for (i = 11, j = 0; i <= 15, j <= 4; i++, j++)
        hora[j] = hora[i];
    hora[5] = '\0';
    return (hora);
}

char *GetPassword(char ReOrNot[]) {
    fflush(stdin);
    system("cls");
    const char Frase[50] = "Type your password :";
    char Senha[50], PasswdAux[50];
    Senha[0] = '\0';
    int LCounter = 0, w = 0;
    PasswdAux[0] = '\0';
    while (PasswdAux[0] != 13) {
        printf("%s%s", ReOrNot, Frase);
        for (w = 1; w <= LCounter; w++) printf("*");
        PasswdAux[0] = getch();
        Senha[LCounter] = PasswdAux[0];
        fflush(stdin);
        system("cls");
        if ((PasswdAux[0] == 8) && (LCounter > 0)) {
            LCounter--;
            Senha[LCounter] = '\0';
        } else if (PasswdAux[0] != 8) LCounter++;

    }
    Senha[LCounter - 1] = '\0';
    system("cls");

    return (Senha);
}
