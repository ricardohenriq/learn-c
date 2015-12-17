#include<stdio.h>
//PROGRAMA QUE CALCULA FATORIAL
int fatorial(int a)
{
    if(a==0)
    {
        return 1;
    }
    else
        return a * fatorial(a-1);
}
int main()
{
    int x;
    int valor;
    printf("Digite um numero para calcular o fatorial\n");
    scanf("%i",&x);
    valor=fatorial(x);
    printf("%i",valor);
    return 0;
}
