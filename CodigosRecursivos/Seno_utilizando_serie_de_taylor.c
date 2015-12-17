#include<stdio.h>
#include<math.h>
//retorna o seno de um número fornecido pelo
//usuário, utilizando a série de Taylor

int fatorial(int n){
	if( n < 2 ) return 1;
	else return n * fatorial(n-1);
}

float seno( float x , int n ){
	if( n == 0 ) return x ;
	else if( n % 2 == 1 ) return seno(x,n-1) - pow(x, (2*n ) +  1 )/fatorial((2*n ) +  1);
	else return seno(x,n-1) + pow(x, (2*n ) +  1)/ fatorial((2*n ) +  1);
}

int main(){
	float RAD = 180/3.14;

	printf("%f\n", seno(  RAD ,0));
	printf("%f\n", seno(  RAD ,1));
	printf("%f\n", seno(  RAD ,2));


	return 0;
}
