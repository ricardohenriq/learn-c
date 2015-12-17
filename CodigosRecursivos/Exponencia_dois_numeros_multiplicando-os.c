#include<stdio.h>
//PROGRAMA QUE FAZ POTENCIA
//MULTIPLICANDO O NUMERO
int expo(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    else
        return a * expo(a, b-1);
}
int main()
{
    int x;
    int y;
    int valor;
    printf("Digite uma base\n");
    scanf("%i",&x);
    printf("Digite um expoente\n");
    scanf("%i",&y);
    valor=expo(x, y);
    printf("%i",valor);
    return 0;
}
