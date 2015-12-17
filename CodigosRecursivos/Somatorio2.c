#include<stdio.h>
//PROGRAMA QUE CALCULA
//SOMATORIO DE 1+1/2+ ... +1/N
float somatorio(float a)
{
    if(a==1)
    {
        return 1;
    }
    else
        return 1/a + somatorio(a-1);
}
int main()
{
    int x;
    float valor;
    printf("Digite ate onde deseja calcular o somatorio\n");
    scanf("%i",&x);
    valor = somatorio(x);
    printf("%f",valor);
    return 0;
}
