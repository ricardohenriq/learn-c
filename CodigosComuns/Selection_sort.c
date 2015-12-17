#include<stdio.h>
#include<stdlib.h>
#define tamanhoVetor 50
typedef int VETOR[tamanhoVetor];

void selection_sort(VETOR vetorAleatorio){

    int contador_1, contador_2, menorValor;

    for(contador_1 = 0; contador_1 < (tamanhoVetor-1); contador_1++){
        //Encontra o PRIMEIRO valor menor
        menorValor = contador_1;
        for (contador_2 = (contador_1+1); contador_2 < tamanhoVetor; contador_2++) {
            //TENTA encontrar um valor menor do que foi encontrado
            //no For Externo
            if(vetorAleatorio[contador_2] < vetorAleatorio[menorValor]) {
                menorValor = contador_2;
            }
        }
        if (contador_1 != menorValor) {
            //Aqui faz a Operação de troca
            int auxiliarTroca = vetorAleatorio[contador_1];
            vetorAleatorio[contador_1] = vetorAleatorio[menorValor];
            vetorAleatorio[menorValor] = auxiliarTroca;
        }
    }
}

void Imprime_Vetor(VETOR vetorAleatorio){

    int contador;

    for(contador = 0; contador < tamanhoVetor; contador++){
    //Imprimindo o VETOR
        if(contador%10 == 0){
            //Para manter uma boa APARENCIA no Prompt
            printf("\n");
        }
        if(vetorAleatorio[contador] < 10){
            //Para fazer com que todos os numeros
            //Tenham a mesma quantidade de algarismos
            printf("| 0%d ",vetorAleatorio[contador]);
            printf("|");
        }else{
            printf("| %d ",vetorAleatorio[contador]);
            printf("|");
        }
    }
    printf("\n\n");

}

int main(){

    VETOR vetorAleatorio;
    int contador;

    srand(time(NULL));
    for(contador = 0; contador < tamanhoVetor; contador++){
        vetorAleatorio[contador] = rand()%(2 * tamanhoVetor);
    }

    printf("Vetor Desordenado\n");
    Imprime_Vetor(vetorAleatorio);
    //Executando ORDENAÇÃO
    selection_sort(vetorAleatorio);
    printf("Vetor Ordenado\n");
    Imprime_Vetor(vetorAleatorio);

    system("pause");
    return(0);
}
