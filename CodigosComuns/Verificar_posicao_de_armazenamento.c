#include <stdlib.h>
#include <stdio.h>
//Verificar Posicao de armazenamento na memoria
 void set() {
     char str[12] = "O rato roeu";
     str[7]=0;
}

 void show() {
     char vet[12];
     printf("vet = '%s'\n", vet);
}

 int main() {
     set();
     show();
     return 0;
}
