#include<stdio.h>
//CALCULO DE FIBONACCI
int fibonacci(int a)
{
    if(a==0)
    {
        return 0;
    }
    if(a==1)
    {
        return 1;
    }
    else
        return fibonacci(a-1) + fibonacci(a-2);
}
int main()
{
    int x;
    int valor;
    printf("Qual posicao do fibonacci voce quer ? \n");
    scanf("%i",&x);
    valor=fibonacci(x);
    printf("%i",valor);
    return 0;
}
