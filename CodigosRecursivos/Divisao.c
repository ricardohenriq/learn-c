#include<stdio.h>
int divisao(int a, int b)
{
    if(a<b)
    {
        return 0;
    }
    else
        return (divisao(a-b , b)+1);
}
int main()
{
    int x;
    int y;
    int valor;
    printf("Digite um numero a ser divido");
    scanf("%i",&x);
    printf("Digite um divisor");
    scanf("%i",&y);
    valor=divisao(x, y);
    printf("%i",valor);
    return 0;
}
