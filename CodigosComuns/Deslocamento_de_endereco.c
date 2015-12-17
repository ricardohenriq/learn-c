#include <stdlib.h>
#include <stdio.h>
struct Person {
int idade;
char nome[30];
char endereco[30];
double salario;
};
int main()
{
struct Person p;
printf("Endereco da estrutura na memoria: %ld\n", (long)&p);
printf("Deslocamento de 'idade': %ld\n", &p.idade);
printf("Deslocamento de 'nome': %ld\n", &p.nome);
printf("Deslocamento de 'endereco': %ld\n", &p.endereco);
printf("Deslocamento de 'salario': %ld\n", &p.salario);
return 0;
}
