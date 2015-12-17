#include<stdio.h>
#define M 15//ordem da matriz
#define N (1+M)*M/2//tamanho do vetor
typedef int matI[N];
void preencher_vetor(matI MTI){
    int i=0;
    for(i=0;i<N;i++){
        MTI[i]=1;
    }
}
void imprimir_matriz(matI MTI){
    int i=0,j=0;
    int k=0;
    int a=0;
    int cont=M;//irá contar a posição onde não irei colocar os zeros
    for(i=0;i<M;i++){
        for(k=M-cont;k>0;k--){
            printf("0 ");
        }
        for(j=0;j<cont;j++){
            printf("%i ",MTI[a]);
            a++;
        }
        printf("\n");
        cont--;
    }
}
int main(){
    matI MTI;
    //MTI significa Matriz triangular inferior
    preencher_vetor(MTI);
    imprimir_matriz(MTI);
    return 0;
}
