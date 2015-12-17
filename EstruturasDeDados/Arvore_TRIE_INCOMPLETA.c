#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMERO_LETRAS 28
/*
=======================
      ARVORE TRIE
=======================
*/

typedef struct Letra{
    char letra;
    int sinal;
    struct Nd *proximo;
}Tipo_Letra;

typedef struct Nd{
    Tipo_Letra Alfabeto[NUMERO_LETRAS];
    struct Nd *Pai;
    int Quantidade_Filhos;
}NODO_Letras;

void Remover_Palavra_Arvore(NODO_Letras *NODO, char palavra[]){

    NODO_Letras *NODO_Atual,*NODO_Pai;
    NODO_Atual = NODO;
    int contador_1 = 0,contador_2,Posicao_Da_Letra = 0;

    while(contador_1 < strlen(palavra)) {
        for(contador_2 = 0; contador_2 < NUMERO_LETRAS; contador_2++) {
            if(palavra[contador_1] == NODO_Atual->Alfabeto[contador_2].letra) {
                Posicao_Da_Letra = contador_2;
            }
        }
        if(contador_1 == strlen(palavra) - 1) {
            if(NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 0) {
                printf("Palavra nao encontrada!\n");
                return;
            }
        } else {
            if(NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 0 || NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 2) {
                printf("Palavra nao encontrada!\n");
                return;
            } else {
                NODO_Atual = NODO_Atual->Alfabeto[Posicao_Da_Letra].proximo;
            }
        }
        contador_1++;
    }
    if(NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 1) {
        printf("Palavra nao pode ser removida pois a mesma pertence a outra palavra!\n");
    } else {
        Posicao_Da_Letra = strlen(palavra) - 1;
        NODO_Pai = NODO_Atual->Pai;
        while(NODO_Atual->Quantidade_Filhos < 2 && NODO_Pai != NULL) {
            free(NODO_Atual);
            NODO_Atual = NODO_Pai;
            NODO_Pai = NODO_Pai->Pai;
            Posicao_Da_Letra--;
        }
        for(contador_1 = 0; contador_1 < NUMERO_LETRAS; contador_1++) {
            if(palavra[Posicao_Da_Letra] == NODO_Atual->Alfabeto[contador_1].letra) {
                NODO_Atual->Alfabeto[contador_1].sinal = 0;
                NODO_Atual->Alfabeto[contador_1].proximo = NULL;
                NODO_Atual->Quantidade_Filhos--;
                printf("Palavra removida!\n");
            }
        }
    }
}

void Buscar_Palavra_Arvore(NODO_Letras *NODO, char palavra[]) {

    NODO_Letras *NODO_Atual;
    NODO_Atual = NODO;
    int contador_1 = 0,contador_2,Posicao_Da_Letra = 0;

    while(contador_1 < strlen(palavra)) {
        for(contador_2 = 0; contador_2 < NUMERO_LETRAS; contador_2++) {
            if(palavra[contador_1] == NODO_Atual->Alfabeto[contador_2].letra) {
                Posicao_Da_Letra = contador_2;
            }
        }
        if(contador_1 == strlen(palavra) - 1) {
            if(NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 0) {
                printf("Palavra nao encontrada!\n");
                return;
            } else {
                printf("Palavra encontrada!\n");
                return;
            }
        } else {

            if(NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 0 || NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 2) {
                printf("Palavra nao encontrada!\n");
                return;
            } else {
                NODO_Atual = NODO_Atual->Alfabeto[Posicao_Da_Letra].proximo;
            }
        }
        contador_1++;
    }
}

void Inserir_Palavra_Arvore(NODO_Letras *NODO, char palavra[]) {

    NODO_Letras *NODO_Atual;
    NODO_Atual = NODO;
    int contador_1 = 0,contador_2,Posicao_Da_Letra = 0;

    while(contador_1 < strlen(palavra)) {
        for(contador_2 = 0; contador_2 < NUMERO_LETRAS; contador_2++) {
            if(palavra[contador_1] == NODO_Atual->Alfabeto[contador_2].letra) {
                Posicao_Da_Letra = contador_2;
                break;
            }
        }
        if(contador_1 == strlen(palavra) - 1) {
            NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal = 2;
            printf("Palavra inserida!\n");
            return;
        } else {
            if(NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal == 1) {
                NODO_Atual = NODO_Atual->Alfabeto[Posicao_Da_Letra].proximo;
            } else {
                NODO_Atual->Alfabeto[Posicao_Da_Letra].proximo = (NODO_Letras*) malloc (sizeof(NODO_Letras));
                Criar_Arvore(NODO_Atual->Alfabeto[Posicao_Da_Letra].proximo);
                NODO_Atual->Alfabeto[Posicao_Da_Letra].sinal = 1;
                NODO_Atual->Quantidade_Filhos++;
                NODO_Atual->Alfabeto[Posicao_Da_Letra].proximo->Pai = NODO_Atual;
                NODO_Atual = NODO_Atual->Alfabeto[Posicao_Da_Letra].proximo;
            }
        }
        contador_1++;
    }
}

void Criar_Arvore(NODO_Letras *NODO) {
    char Alfabeto[NUMERO_LETRAS] = "ABCDEFGHIJKLMNOPQRSTUVXWYZ# ";
    NODO->Quantidade_Filhos = 0;
    NODO->Pai = NULL;
    int contador_1;

    for(contador_1 = 0; contador_1 < NUMERO_LETRAS; contador_1++) {
        NODO->Alfabeto[contador_1].sinal = 0;
        NODO->Alfabeto[contador_1].letra = Alfabeto[contador_1];
        NODO->Alfabeto[contador_1].proximo = NULL;
    }
}

int main(){
    NODO_Letras Arvore_Trie;
    Criar_Arvore(&Arvore_Trie);
    int opcao;

    char palavra[100];
    do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Inserir uma palavra na arvore\n");
		printf("\t2 - Excluir uma palavra da arvore\n");
		printf("\t3 - Buscar palavra na arvore\n");
		printf("\t0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				break;
			case 1:
                printf("Insira um palavra para ser inserida: ");
                scanf("%[^\n]",&palavra);
                Inserir_Palavra_Arvore(&Arvore_Trie,palavra);
				break;
			case 2:
                printf("Insira um palavra para ser removida: ");
                scanf("%[^\n]",&palavra);
                Remover_Palavra_Arvore(&Arvore_Trie,palavra);
				break;
			case 3:
                printf("Insira um palavra para ser buscada: ");
                scanf("%[^\n]",&palavra);
                Buscar_Palavra_Arvore(&Arvore_Trie,palavra);
				break;
			default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
	system("pause");
	return 0;
}













