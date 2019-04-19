int LineCounter() {
    int Lines = 0;
    Lines = 0;
    char Frase[310];
    Frase[0] = '\0';
    FILE *VerifyLinesOf = fopen(LOCAL, "r");
    while (!(feof(VerifyLinesOf))) {
        Frase[0] = '\0';

        fgets(Frase, 300, VerifyLinesOf);
        if (strlen(Frase) > 0)
            Lines++;
    }
    fclose(VerifyLinesOf);
    return (Lines);
}

void WriteOnScreen(int Start) {
    char Buffer[200];
    Buffer[0] = '\0';
    FILE *Write = fopen(LOCAL, "r");
    int count = 0;
    while (!(feof(Write))) {
        count++;
        fgets(Buffer, 190, Write);
        if (count > Start)
            printf("%s", Encript(Buffer, 1));
        if (LineCounter() == count) break;

    }
    fclose(Write);

}
