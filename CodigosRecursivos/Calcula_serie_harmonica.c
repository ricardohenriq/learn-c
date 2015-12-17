#include<stdio.h>

float soma(float n){
	if(n == 1) return 1;
	else return 1/n + soma(n-1);
}

int main(){
	printf("%f", soma(5));
return 0;
}
