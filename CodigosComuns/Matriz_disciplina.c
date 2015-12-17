#include<stdio.h>
#define MAXL 6
#define MAXC 5
typedef int MAT[MAXL][MAXC];
void imprimir_matriz(MAT matematica){
    int i=0,j=0;
    for(i=0;i<MAXL;i++){
        for(j=0;j<MAXC;j++){
            printf("%i  ",matematica[i][j]);
        }
        printf("\n");
    }
}
void zerar_matriz(MAT matematica){
    int i=0,j=0;
    for(i=0;i<MAXL;i++){
        for(j=0;j<MAXC;j++){
            matematica[i][j]=0;
        }
    }
}
void preencher_matricula(MAT matematica){
    int i=0;
    for(i=0;i<MAXL;i++){
        matematica[i][0]=12345+i;
    }
    matematica[MAXL-1][0]=11111;//ISSO NÃO É UM NUMERO DE MATRICULA É SOMENTE PARA QUE
    //O CAMPO ONDE FICA AS MEDIA POR COLUNA NÃO FIQUE DESALINHADO/VAZIO.
    matematica[MAXL-1][MAXC-1]=11;//ISSO NÃO É A MEDIA DAS MEDIAS POR ALUNO É SOMENTE PARA QUE
    //O ULTIMO CAMPO NÃO FIQUE DESALINHADO/VAZIO.
}
void preencher_notas(MAT matematica){
    int i=0,j=1;
    for(j=1;j<MAXC-1;j++){
        for(i=0;i<MAXL-1;i++){
            do{
                printf("Digite a nota %i do aluno %i.\n",j,matematica[i][0]);
                scanf("%i",&matematica[i][j]);
            }while((matematica[i][j]<0)||(matematica[i][j]>10));
        }
    }
}
void media_coluna(MAT matematica){
    int i=0,j=1;
    int acumulador=0;
    for(j=1;j<MAXC-1;j++){
        for(i=0;i<MAXL;i++){
            acumulador+=matematica[i][j];
        }
        matematica[MAXL-1][j]=acumulador/(MAXL-2);
        acumulador=0;
    }
}
void media_linha(MAT matematica){
    int i=0,j=1;
    int acumulador=0;
    for(i=0;i<MAXL-1;i++){
        for(j=1;j<MAXC-1;j++){
            acumulador+=matematica[i][j];
        }
        matematica[i][MAXC-1]=acumulador/(MAXC-2);
        acumulador=0;
    }
}
int main(){
    MAT matematica;
    zerar_matriz(matematica);
    preencher_matricula(matematica);
    preencher_notas(matematica);
    media_coluna(matematica);
    media_linha(matematica);
    imprimir_matriz(matematica);
    return 0;
}
