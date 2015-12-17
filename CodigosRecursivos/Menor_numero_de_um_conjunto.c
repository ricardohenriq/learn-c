#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Retorna o Menor numero de um conjunto enviado pelo usuario

float menor_elemento(float vetor[], int inicio, int fim){
	if( inicio == fim ) return vetor[inicio];
	else if( vetor[inicio] < vetor[fim] ) return menor_elemento(vetor, inicio, fim -1 );
	else return menor_elemento(vetor, inicio + 1, fim);
}

int main(){
	float vetor[10];
	int i;
	puts("nbnb");
	for(i = 0 ; i < 10 ; i++) {
		float a =  (float)(rand() % 100) / (rand() % 8) * 5 ; //gera os numeros aleatoriamente
		printf("%.2f ",a);
		vetor[i] = a;
	}

	printf("\nmenor: %.2f\n", menor_elemento(vetor, 0,9));
	return 0;
}
