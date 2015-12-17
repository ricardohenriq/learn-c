#include <stdio.h>
#include<stdlib.h>
#define MAXF 100
//MAXF e o tamanho
//da Fila Estatica

/*
===================================
          FILA ESTATICA
===================================
*/

//APARENTEMENTE 100 POR CENTO

typedef struct{
	int codigo;//Codigo de pessoa //Chave Primaria
	char nome[40];
	char telRes[13]; //(__)____-____
	char telCel[13]; //(__)____-____
}Tipo_Pessoa;

typedef struct{
	Tipo_Pessoa pessoas[MAXF];
	int inicio, fim;
	int contador;
}Fila_Estatica;

/*
===========FUNCOES==========
Criar Fila Vazia
Enfileirar Elemento
Desenfileirar Elemento
Ler Elemento
Exibir Elemento
===========FUNCOES==========
*/

void Ler_Pessoa(Tipo_Pessoa *pessoa){
	printf("Informe o codigo da pessoa: ");
	scanf("%d*c",&pessoa->codigo);
	getchar();
	printf("Informe o nome da pessoa: ");
	scanf("%[^\n]",&pessoa->nome);
	getchar();
	printf("Informe o telefone residencial: ");
	scanf("%[^\n]",&pessoa->telRes);
	getchar();
	printf("Informe o telefone celular: ");
	scanf("%[^\n]",&pessoa->telCel);
}

void Criar_Fila_Vazia(Fila_Estatica *fila){
	fila->inicio = 0;
	fila->fim = 0;
	fila->contador = 0;
}

void Enfileirar_Elemento(Fila_Estatica *fila, Tipo_Pessoa pessoa){
	if(((fila->fim+1)%MAXF) == fila->inicio){
		printf("A FILA ESTA CHEIA!\n");
	}else{
		fila->pessoas[fila->fim] = pessoa;
		fila->fim = (fila->fim+1)%MAXF;
		fila->contador++;
		printf("PESSOA ENFILEIRADA COM SUCESSO!\n");
	}
}

void Desenfileirar_Elemento(Fila_Estatica *fila, Tipo_Pessoa *pessoa){
	if(fila->fim == fila->inicio){
		printf("A FILA ESTA VAZIA!\n");
	}else{
		*pessoa = fila->pessoas[fila->inicio];
		fila->inicio = (fila->inicio+1)%MAXF;
		fila->contador--;
		printf("PESSOA DESENFILEIRADA COM SUCESSO!\n");
	}
}

void Exibir_Pessoa(Tipo_Pessoa pessoa){
	printf("Codigo:\t\t%d\n", pessoa.codigo);
	printf("Nome:\t\t%s\n", pessoa.nome);
	printf("Tel. Res:\t%s\n", pessoa.telRes);
	printf("Tel. Cel:\t%s\n\n", pessoa.telCel);
}

void Mostrar_Informacoes_Pessoa(Fila_Estatica *fila, Tipo_Pessoa pessoa){

    int contador_posicoes;//Posicoes do VETOR

    if(fila->contador == 0){
        printf("A FILA ESTA VAZIA!\n");
    }else{
        printf("INFORME O CODIGO DA PESSOA: ");
        scanf("%d", &pessoa.codigo);
        for(contador_posicoes = fila->inicio; contador_posicoes < fila->fim; contador_posicoes++){
            if(pessoa.codigo == fila->pessoas[contador_posicoes].codigo){
                Exibir_Pessoa(fila->pessoas[contador_posicoes]);
                break;
            }
        }
        if(contador_posicoes == fila->fim){
            printf("PESSOA NAO ENCONTRADA!\n");
        }
    }
}

void Exibir_Fila(Fila_Estatica *fila){

    int contador_posicoes;//Posicoes do VETOR

    if(fila->contador == 0){
        printf("A FILA ESTA VAZIA!\n");
    }else{
        printf("----------- FILA -----------\n");
        for(contador_posicoes = fila->inicio; contador_posicoes < fila->fim; contador_posicoes++){
            Exibir_Pessoa(fila->pessoas[contador_posicoes]);
        }
        printf("----------- FILA -----------\n");
    }
}

int main(){

	Fila_Estatica fila;
	Tipo_Pessoa pessoa;
	int opcao;

	Criar_Fila_Vazia(&fila);

	do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Enfileirar uma pessoa\n");
		printf("\t2 - Desenfileirar uma pessoa\n");
		printf("\t3 - Mostrar informacoes de uma pessoa\n");
		printf("\t4 - Exibir fila (do PRIMEIRO para o ULTIMO)\n");
		printf("\t0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				break;
			case 1:
				Ler_Pessoa(&pessoa);
				Enfileirar_Elemento(&fila, pessoa);
				break;
			case 2:
				Desenfileirar_Elemento(&fila, &pessoa);
				break;
			case 3:
                Mostrar_Informacoes_Pessoa(&fila, pessoa);
				break;
			case 4:
                Exibir_Fila(&fila);
				break;
			default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
    system("pause");
	return 0;
}
