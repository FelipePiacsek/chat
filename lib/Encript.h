char* Encript(char *Word,int Parameter)
{
    int j;
    int num;
    for (j=0;j<strlen(Word);j++)
    {
        num=Word[j];
        if (Word[j]!='\n')
        {
          if (Parameter==0)
                num+=7;
            else
                num-=7;
        Word[j]=num;
        }
    }
    return(Word);
}
