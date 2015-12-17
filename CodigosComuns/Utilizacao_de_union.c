#include <stdlib.h>
#include <stdio.h>
//Exemplo de manipulacao de union e struct
struct Chars {
    char a;
    char b;
    char c;
    char d;
};
union Values {
    int num;
    char str[4];
    struct Chars chs;
};
int main(){
    union Values vs;
    printf("Tamanho: %ld\n", sizeof(union Values));
    vs.num = 0;
    vs.chs.a = 1;
    printf("num: %d\n", vs.num);
    vs.num = 0;
    vs.chs.b = 4;
    printf("num: %d\n", vs.chs.b);
    vs.str[1] = 0;
    printf("num: %d\n", vs.num);
    vs.num = 0x00617655; /* Número 32 bits em hexadecimal */
    printf("num: %d\n", vs.num);
    printf("str: %s\n", vs.str);
    return 0;
}
