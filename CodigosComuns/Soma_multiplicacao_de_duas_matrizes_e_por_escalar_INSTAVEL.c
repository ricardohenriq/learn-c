#include<stdio.h>
#define N 3
#define M 2
#define W 4
typedef int matA[N][M];
typedef int matB[M][W];
typedef int matC[N][W];
void soma(matA A1,matA A2, matA A3){
	int i=0,j=0;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			A3[i][j]=A1[i][j]+A2[i][j];
		}
	}
}
void produto(matA A1,matB B, matC C){
	int i=0,j=0;
	//faço um for para cada linha da matriz resultante
    for(j=0;j<W;j++){
        C[0][j]=(A1[0][0]*B[0][j])+(A1[0][1]*B[1][j]);
	}
	for(j=0;j<W;j++){
        C[1][j]=(A1[1][0]*B[0][j])+(A1[1][1]*B[1][j]);
	}
	for(j=0;j<W;j++){
        C[2][j]=(A1[2][0]*B[0][j])+(A1[2][1]*B[1][j]);
	}
}
void produto_escalar(matC C,matC D){
    int i=0,j=0;
    for(i=0;i<N;i++){
        for(j=0;j<W;j++){
            D[i][j]=C[i][j]*2;
        }
    }
}
 int main(){
	matA A1,A2,A3;
	matB B;
	matC C,D;
	int i=0,j=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			A1[i][j]=i+j;
			A2[i][j]=2*i+2*j;
			A3[i][j]=0;
		}
	}

	for(i=0;i<M;i++){
		for(j=0;j<W;j++){
		    B[i][j]=5;
		}
	}

	soma(A1,A2,A3);
	produto(A1,B,C);
    produto_escalar(C,D);
	printf("Matriz A1 \n");
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%i	",A1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matriz A2 \n");
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%i	",A2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matriz A3 \n");
	printf("\n");
    for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%i	",A3[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matriz B \n");
	printf("\n");
	for(i=0;i<M;i++){
		for(j=0;j<W;j++){
		    printf("%i	",B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
    printf("Matriz C \n");
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<W;j++){
		    printf("%i	",C[i][j]);
		}
		printf("\n");
	}
	printf("\n");
    printf("Matriz D \n");
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<W;j++){
		    printf("%i	",D[i][j]);
		}
		printf("\n");
	}
	return 0;
}
