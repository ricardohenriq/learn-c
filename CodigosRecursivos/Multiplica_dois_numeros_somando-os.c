#include<stdio.h>
//MULTIPLICA 2 NUMEROS
//SOMANDO-OS
int multi(int a, int b)
{
    if(b==1)
    {
        return a;
    }
    else
        return a + multi(a, b-1);
}
int main()
{
    int x;
    int y;
    int valor;
    printf("Digite um numero a ser multiplicado");
    scanf("%i",&x);
    printf("Digite um numero que ira multiplicar");
    scanf("%i",&y);
    valor=multi(x, y);
    printf("%i",valor);
    return 0;
}
