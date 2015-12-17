#include<stdio.h>
int m90[3][3];
int m[3][3];
int i;
int j;
void rotaciona(int m9[3][3]){
    for(i=0;i<3;i++) {
        if(i==0){
            for(j=0;j<3;j++){
                m90[j][2]=m[i][j];
            }
        }
        if(i==1){
            for(j=0;j<3;j++){
                m90[j][1]=m[i][j];
            }
        }
        if(i==2){
            for(j=0;j<3;j++){
                m90[j][0]=m[i][j];
            }
        }
    }
}
int main()
{
    int i;
    int j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Digite um numero a preencher na matriz: ");
            scanf("%i", &m[i][j]);
        }
    }
    rotaciona(m[3][3]);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%i",m[i][j]);
        }
        printf("\n");
    }
    printf("\n \n\ \n\ \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%i",m90[i][j]);
        }
        printf("\n");
    }
        return 0;
}
