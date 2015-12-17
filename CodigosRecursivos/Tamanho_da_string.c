#include<stdio.h>
#include<string.h>
//VER O TAMANHO DA STRING
//USANDO RECURSIVIDADE
int tam(char stri[])
{
    if(stri[0]=='\0')
    {
        return 0;
    }
    else
        return 1+tam(&stri[1]);
}
int main()
{
    char str[100];
    int t;
    printf("Digite uma string\n");
    gets(str);
    t=tam(str);
    printf("%i",t);
    return 0;
}
