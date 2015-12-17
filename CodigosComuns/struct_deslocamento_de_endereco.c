#include <stdlib.h>
#include <stdio.h>
struct Campos {
int a;
int b;
int c;
};
int main()
{
struct Campos n;
n.a = 1111;
n.b = 2222;
n.c = 3333;
printf("Valor: %d\n", *( (int*)( ((short*)&n) + 4) ) );
printf("Valor: %d\n", *( (int*)( ((char*)&n) + 8) ) );
return 0;
}
