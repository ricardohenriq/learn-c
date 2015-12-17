#include <stdio.h>
#include<stdlib.h>
#define MAXL 10
//MAXL e o tamanho
//da Pilha Estatica

/*
===================================
     LISTA SEQUENCIAL ESTATICA
===================================
*/

//VERIFICAR SE A PESSOA JA ESTAVA NA LISTA

typedef struct{
	int codigo;//Codigo de pessoa //Chave primaria
	char nome[40];
	char telRes[13]; //(__)____-____
	char telCel[13]; //(__)____-____
}Tipo_Pessoa;

typedef struct{
	Tipo_Pessoa pessoas[MAXL];
	int primeiro, ultimo;
}Lista_Sequencial_Estatica;

/*
===========FUNCOES==========
Criar Lista Vazia
Ler Elemento
Inserir Pessoa Na Lista
Remover Pessoa Da Lista
Exibir Lista
Verificar Lista Sequencial Estatica Cheia
Verificar Lista Sequencial Estatica Vazia
===========FUNCOES==========
*/

void Criar_Lista_Vazia(Lista_Sequencial_Estatica *lista){
	lista->primeiro = 0;// Equivalente a (*lista).primeiro = 0;
	lista->ultimo = 0;
}

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

int Verificar_Lista_Cheia(Lista_Sequencial_Estatica *lista){
	return (lista->ultimo==MAXL);
}

int Verificar_Lista_Vazia(Lista_Sequencial_Estatica *lista){
	return (lista->ultimo==lista->primeiro);
}

void Inserir_Pessoa_Lista(Lista_Sequencial_Estatica *lista, Tipo_Pessoa pessoa){
	int Indice_Lista; // Usada para percorrer a lista de pessoas
	int Indice_Pessoa; // Usada para organizar as pessoas na lista
	if(Verificar_Lista_Cheia(lista)){
		printf("A LISTA ESTA CHEIA!\n");
	}else{
		for(Indice_Lista = lista->primeiro; (Indice_Lista!=lista->ultimo) && (pessoa.codigo > lista->pessoas[Indice_Lista].codigo); Indice_Lista++);
		if(Indice_Lista == lista->ultimo){
			lista->pessoas[Indice_Lista] = pessoa;
			lista->ultimo++;
		}else{
			for(Indice_Pessoa = lista->ultimo; Indice_Pessoa > Indice_Lista; Indice_Pessoa--){
				lista->pessoas[Indice_Pessoa] = lista->pessoas[Indice_Pessoa-1];
			}
			lista->pessoas[Indice_Lista] = pessoa;
			lista->ultimo++;
		}
		printf("PESSOA INSERIDA NA LISTA COM SUCESSO!\n");
	}
}

void Remover_Pessoa_Lista(Lista_Sequencial_Estatica *lista, Tipo_Pessoa *pessoa){
	int Indice_Lista; // Usada para percorrer a lista de pessoas
	int Indice_Pessoa; // Usada para organizar as pessoas na lista
	if(Verificar_Lista_Vazia(lista)){
		printf("A LISTA ESTA VAZIA!\n");
	}else{
		for(Indice_Lista=lista->primeiro; (Indice_Lista!=lista->ultimo) && (pessoa->codigo > lista->pessoas[Indice_Lista].codigo); Indice_Lista++);
		if((Indice_Lista==lista->ultimo) || (lista->pessoas[Indice_Lista].codigo != pessoa->codigo)){
			printf("ELEMENTO NAO ENCONTRADO!\n");
		}else{
			*pessoa=lista->pessoas[Indice_Lista];
			for(Indice_Pessoa=Indice_Lista; Indice_Pessoa<lista->ultimo; Indice_Pessoa++){
				lista->pessoas[Indice_Pessoa]=lista->pessoas[Indice_Pessoa+1];
			}
			lista->ultimo--;
			printf("PESSOA EXCLUIDA DA LISTA COM SUCESSO!\n");
		}
	}
}

void Exibir_Lista(Lista_Sequencial_Estatica *lista){
	int contador_posicoes;//Posicoes do VETOR
	if(lista->primeiro == lista->ultimo){
		printf("A LISTA ESTA VAZIA!\n");
	}
	printf("----------- LISTA -----------\n");
	for(contador_posicoes = lista->primeiro; contador_posicoes<lista->ultimo; contador_posicoes++){
		printf("Codigo:\t\t%d\n", lista->pessoas[contador_posicoes].codigo);
		printf("Nome:\t\t%s\n", lista->pessoas[contador_posicoes].nome);
		printf("Tel. Res:\t%s\n", lista->pessoas[contador_posicoes].telRes);
		printf("Tel. Cel:\t%s\n\n", lista->pessoas[contador_posicoes].telCel);

	}
	printf("----------- LISTA -----------\n");
}

int main(){


	Lista_Sequencial_Estatica lista;
	Tipo_Pessoa pessoa;
	Criar_Lista_Vazia(&lista);
	int opcao;

	do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Inserir uma pessoa na lista\n");
		printf("\t2 - Excluir uma pessoa da lista\n");
		printf("\t3 - Mostrar lista\n");
		printf("\t0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				break;
			case 1:
				Ler_Pessoa(&pessoa);
				Inserir_Pessoa_Lista(&lista, pessoa);
				break;
			case 2:
				printf("INFORME O CODIGO DA PESSOA: ");
				scanf("%d", &pessoa.codigo);
				Remover_Pessoa_Lista(&lista, &pessoa);
				break;
			case 3:
				Exibir_Lista(&lista);
				break;

			default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
    system("pause");
	return 0;
}
