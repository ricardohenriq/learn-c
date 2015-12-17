#include<stdio.h>
#include<string.h>
//INVERTER STRING COM
//RECURSIVIDADE
void inverte(char str[])
{
    if(str[0]!='\0')
    {
        inverte(&str[1]);
        printf("%c",str[0]);
    }
}
int main()
{
    char string[100];
    printf("Digite um string\n");
    gets(string);
    inverte(string);
    return 0;
}
