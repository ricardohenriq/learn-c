#include<stdio.h>
//CALCULA PI
float pi(int a)
{
    float denominador;
    float fracao;
    if(a==1)
    {
        return 1;
    }
    denominador = a * 2 - 1;
    fracao = 1/denominador;
    if(a%2==0)
    {
        return - fracao + pi(a-1);
    }
    else
        return + fracao + pi(a-1);
}
int main()
{
    int x;
    float valor;
    printf("Digite a onde voce quer calcular PI");
    scanf("%i",&x);
    valor = pi(x);
    valor = valor * 4;
    printf("%f",valor);
    return 0;
}
