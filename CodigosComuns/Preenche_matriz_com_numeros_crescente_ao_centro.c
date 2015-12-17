#include <stdio.h>
//PREENCHE AS BORDAS COM UM NUMERO
//DEPOIS AS MAS DO CENTRO COM NUMERO-1
//E ASSIM SUCESSIVAMENTE
int main(){
    int n,i,j,z,m;
    printf("Digite a dimensao da matriz: ");
    scanf("%i",&n);
    int ma[n][n];
    z=0;m=-1;
    for(j=0;j<(n/2+1);j++){
        z++;
        m++;
        for (i=0+m;i<n-m;i++){
            ma[i][j]=j+1;
            ma[j][i]=j+1;
            ma[n-z][i]=j+1;
            ma[i][n-z]=j+1;
        }
    }
    for (i=0;i<n;i++){
    printf("\n");
        for(j=0;j<n;j++){
        printf("%d ",ma[i][j]);
        }
    }
    return 0;
}
