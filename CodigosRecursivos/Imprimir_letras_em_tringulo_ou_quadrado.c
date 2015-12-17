#include <stdio.h>
//IMPRIMIR LETRAS EM TRIANGULO
//OU QUADRADO RECURSIVO
char imprime(int n, int t)
{   char letras[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    if (n==1)
    {   printf("%c\n", letras[0]);
        return 0;
    }
    else
    {
        printf("%c", letras[n-1]);
        imprime(n-1,t);
        return 0;
    }
}
int main()
{
    int x, y, z, i=0;
    do
    {   printf("Informe quantas letras do alfabeto ira utilizar:");
        scanf("%i", &x);
        printf("Informe se sera um triangulo(numero=0) ou um retangulo(numero=1):");
        scanf("%i", &y);
    }while(x<1 || x>26 || x<1 && y<0 && y>1 || x>26 && y<0 && y>1);
    z=x;
    for (i=0; i<z;i++)
    {
        if(y==0)
        {
            imprime(x,y);
            x--;
        }
        else
        {
            imprime(x,y);
        }
    }
    return 0;
}
