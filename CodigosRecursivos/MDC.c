#include<stdio.h>
int mdc(int x, int y)
{
    if((x>=y)&&(x%y==0))
    {
        return y;
    }
    if(x<y)
    {
        return mdc(y, x);
    }
    else
        return mdc(y, x%y);
}
int main()
{
    int a;
    int b;
    int valor;
    printf("Digite um numero para calcular o MDC");
    scanf("%i",&a);
    printf("Digite um numero para calcular o MDC");
    scanf("%i",&b);
    valor=mdc(a, b);
    printf("%i",valor);
    return 0;
}
