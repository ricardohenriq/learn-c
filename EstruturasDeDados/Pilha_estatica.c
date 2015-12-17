#include<stdio.h>
#include<stdlib.h>
#define MAXP 100
//MAXP e o tamanho
//da Pilha Estatica

/*
===================================
          PILHA ESTATICA
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
	Tipo_Pessoa pessoas[MAXP];
	int TOPO;
}Pilha_Estatica;

/*
===========FUNCOES==========
Criar Pilha Vazia
Empilhar Elemento
Desempilhar Elemento
Ler Elemento
Exibir Elemento
Verificar Pilha Estatica Cheia
Verificar Pilha Estatica Vazia
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

void Criar_Pilha_Vazia(Pilha_Estatica *pilha){
	pilha->TOPO=0;
}

int Verificar_Pilha_Vazia(Pilha_Estatica pilha){
	return (pilha.TOPO==0);
}

int Verificar_Pilha_Cheia(Pilha_Estatica pilha){
	return (pilha.TOPO==MAXP);
}

void Empilhar_Elemento(Pilha_Estatica *pilha, Tipo_Pessoa pessoa){
	if(Verificar_Pilha_Cheia(*pilha)){
		printf("A PILHA ESTA CHEIA!\n");
	}else{
		pilha->pessoas[pilha->TOPO] = pessoa;
		pilha->TOPO++;
		printf("PESSOA EMPILHADA COM SUCESSO!\n");
	}
}

void Desempilhar_Elemento(Pilha_Estatica *pilha, Tipo_Pessoa *pessoa){
	if(Verificar_Pilha_Vazia(*pilha)){
		printf("A PILHA ESTA VAZIA!\n");
	}else{
		pilha->TOPO--;
		*pessoa = pilha->pessoas[pilha->TOPO];
		printf("PESSOA DESEMPILHADA COM SUCESSO!\n");
	}
}

void Exibir_Pessoa(Tipo_Pessoa pessoa){
	printf("Codigo:\t\t%d\n", pessoa.codigo);
	printf("Nome:\t\t%s\n", pessoa.nome);
	printf("Tel. Res:\t%s\n", pessoa.telRes);
	printf("Tel. Cel:\t%s\n\n", pessoa.telCel);
}

void Mostrar_Informacoes_Pessoa(Pilha_Estatica *pilha, Tipo_Pessoa pessoa){

    int contador_posicoes;//Posicoes do VETOR

    if(Verificar_Pilha_Vazia(*pilha)){
        printf("A PILHA ESTA VAZIA!\n");
    }else{
        printf("INFORME O CODIGO DA PESSOA: ");
        scanf("%d", &pessoa.codigo);
        for(contador_posicoes = 0; contador_posicoes < pilha->TOPO; contador_posicoes++){
            if(pessoa.codigo == pilha->pessoas[contador_posicoes].codigo){
                Exibir_Pessoa(pilha->pessoas[contador_posicoes]);
                break;
            }
        }
        if(contador_posicoes == pilha->TOPO){
            printf("PESSOA NAO ENCONTRADA!\n");
        }
    }
}

void Exibir_Pilha(Pilha_Estatica *pilha){

    int contador_posicoes;//Posicoes do VETOR

    if(Verificar_Pilha_Vazia(*pilha)){
        printf("A PILHA ESTA VAZIA!\n");
    }else{
        printf("----------- PILHA -----------\n");
        for(contador_posicoes = pilha->TOPO-1; contador_posicoes >= 0; contador_posicoes--){
            Exibir_Pessoa(pilha->pessoas[contador_posicoes]);
        }
        printf("----------- PILHA -----------\n");
    }
}

int main(){

	Pilha_Estatica pilha;
	Tipo_Pessoa pessoa;
	int opcao;

	Criar_Pilha_Vazia(&pilha);

	do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Empilhar pessoa\n");
		printf("\t2 - Desempilhar pessoa\n");
		printf("\t3 - Mostrar informacoes de uma pessoa\n");
		printf("\t4 - Exibir pilha (do TOPO a BASE)\n");
		printf("\t0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				break;
			case 1:
				Ler_Pessoa(&pessoa);
				Empilhar_Elemento(&pilha, pessoa);
				break;
			case 2:
				Desempilhar_Elemento(&pilha, &pessoa);
				break;
			case 3:
                Mostrar_Informacoes_Pessoa(&pilha, pessoa);
				break;
			case 4:
                Exibir_Pilha(&pilha);
				break;
			default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
    system("pause");
	return 0;
}
