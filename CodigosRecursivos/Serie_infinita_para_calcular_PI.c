#include<stdio.h>
float pi( int n){
	if( n == 1 ) return 4;
	else if(  n%2 ) return 4 * (1/( ((float) n * 2 ) - 1 ) )+ pi(n-1) ; //se n%2 for O o teste da falso e vai pro else, se der um numero é impar e entra no if
	else return 4 *( -1/( ( (float)n * 2 ) - 1 )) + pi(n-1);
}

int main(){
	printf("%f",pi(628));
return 0;
}
