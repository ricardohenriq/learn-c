#include<stdio.h>
int bas;
int expo;
int resultado;
int potencia(int base, int expoente)
{
    if (expoente==0)//tem que colocar o nome do parametro
        return 1;
    else //preste atenção pq 2³ e igual a 2²*2 //sempre ter conhecimento sobre matematica
        return base * potencia (base, (expoente - 1));

}
int frase(char frase[])
{
    int valor;
    printf(frase);
    scanf("%i", &valor);
}
int main()
{
    bas=frase("Digite um valor pare ser a base");
    expo=frase("Digite um valor para ser o expoente");
    resultado=potencia(bas, expo);
    printf("%i",resultado);
    return 0;
}
