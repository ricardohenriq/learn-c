#include<stdio.h>
#include<string.h>
//CONTA QUANTAS LETRAS
//APARECE RECURSIVAMENTE
int caractere(char stri[], char letr)
{
    if(stri[0]=='\0')
    {
        return 0;
    }
    if(stri[0]==letr)
    {
        return (1+caractere(++stri, letr));
    }
    else
        return caractere(++stri, letr);
}
int main()
{
    char str[100];
    char letra;
    int t;
    printf("Digite uma frase\n");
    gets(str);
    printf("Digite uma letra\n");
    scanf("\n%c",&letra);
    t=caractere(str, letra);
    printf("%i",t);
    return 0;
}
