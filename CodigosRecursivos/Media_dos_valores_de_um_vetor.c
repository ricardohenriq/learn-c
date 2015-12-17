#include<stdio.h>
//MEDIA DOS VALORES DE UM VETOR
//USANDO RECURSIVIDADE
float media(int vet[10], int pos)
{
    float soma;
    if(pos==10)
    {
        return 0;
    }
    else
        return soma=vet[pos]+media(vet, pos+1);
}
int main()
{
    int vetor[10];
    int i;
    float med;
    for(i=0;i<10;i++)
    {
        printf("Digite um numero\n");
        scanf("%i",&vetor[i]);
    }
    med=media(vetor, 0);
    med=med/10;
    printf("%f",med);
    return 0;
}
