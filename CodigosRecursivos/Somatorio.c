#include<stdio.h>
//PROGRAMA CALUCULA A SOMA DOS NUMEROS
//EX: 123=6, 100=1.
int soma_dos_numeros(int a)
{
    if(a==0)
    {
        return 0;
    }
    else
        return (a%10)+soma_dos_numeros(a/10);
}
int main()
{
    int x;
    int valor;
    printf("Digite um numero");
    scanf("%i",&x);
    valor=soma_dos_numeros(x);
    printf("%i",valor);
    return 0;
}
