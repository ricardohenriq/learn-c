#include <stdlib.h>
#include <stdio.h>
//Calcula Endereco
int mat[4][3] = {
    { 1, 2, 3},
    { 4, 5, 6},
    { 7, 8, 9},
    {10, 11, 12}
};
int main(){
    int value;
    int *ptr;
    int lin = 2;
    int col = 1;
    ptr = (int*)mat;
    value = *( ptr + (lin * 3) + col );;
    printf("%d == %d\n", mat[lin][col], value);
    return EXIT_SUCCESS;
}
