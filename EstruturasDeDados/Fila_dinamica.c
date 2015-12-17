#include<stdio.h>
#include<stdlib.h>

/*
===================================
          FILA DINAMICA
===================================
*/

typedef struct{
	int codigo;//Codigo de pessoa //Chave Primaria
	char nome[40];
	char telRes[13]; //(__)____-____
	char telCel[13]; //(__)____-____
}Tipo_Pessoa;

typedef struct cx {
    Tipo_Pessoa pessoas;
    struct cx *proximo;
}CAIXA;

typedef CAIXA *ponteiro;

typedef struct{
    ponteiro INICIO,FIM;
    int contador;
}Fila_Dinamica;

/*
===========FUNCOES==========
Criar Fila Vazia
Enfileirar Elemento
Desenfileirar Elemento
Ler Elemento
Exibir Elemento
===========FUNCOES==========
*/

void Criar_Fila_Vazia(Fila_Dinamica *fila){
    fila->INICIO = (ponteiro)malloc(sizeof(CAIXA));
    fila->FIM = fila->INICIO;
    fila->FIM->proximo = NULL;
    fila->contador = 0;
}

void Enfileirar_Elemento(Fila_Dinamica *fila, Tipo_Pessoa pessoa){
    ponteiro auxiliar;
    auxiliar = (ponteiro)malloc(sizeof(CAIXA));
    auxiliar->pessoas = pessoa;
    auxiliar->proximo = fila->FIM->proximo;//NULL
    fila->FIM->proximo = auxiliar;
    fila->FIM = auxiliar;
    fila->contador++;
    printf("PESSOA ENFILEIRADA COM SUCESSO!\n");
}

void Desenfileirar_Elemento(Fila_Dinamica *fila, Tipo_Pessoa *pessoa){
    ponteiro auxiliar;
    if(fila->INICIO == fila->FIM){
        printf("A FILA ESTA VAZIA.\n");
    }else{
        auxiliar = fila->INICIO;
        fila->INICIO = auxiliar->proximo;
        *pessoa = fila->INICIO->pessoas;
        fila->contador--;
        free(auxiliar);
        printf("PESSOA DESENFILEIRADA COM SUCESSO!\n");
    }
}

void Ler_Pessoa(Tipo_Pessoa *pessoa){
	printf("Informe o codigo da pessoa: ");
	scanf("%d*c", &pessoa->codigo);
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

void Exibir_Pessoa(Tipo_Pessoa pessoa){
	printf("Codigo:\t\t%d\n", pessoa.codigo);
	printf("Nome:\t\t%s\n", pessoa.nome);
	printf("Tel. Res:\t%s\n", pessoa.telRes);
	printf("Tel. Cel:\t%s\n\n", pessoa.telCel);
}

void Exibir_Fila(Fila_Dinamica *fila){
    ponteiro auxiliar;
    auxiliar = fila->INICIO->proximo;

    if(fila->INICIO == fila->FIM){
        printf("A FILA ESTA VAZIA.\n");
    }else{
        while(auxiliar != NULL){
            Exibir_Pessoa(auxiliar->pessoas);
            auxiliar = auxiliar->proximo;
        }
    }
}

int main(){

    Fila_Dinamica fila;
	Tipo_Pessoa pessoa;
	int opcao;

	Criar_Fila_Vazia(&fila);

	do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Enfileirar uma pessoa\n");
		printf("\t2 - Desenfileirar uma pessoa\n");
		printf("\t3 - Exibir fila (do PRIMEIRO para o ULTIMO)\n");
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
                Exibir_Fila(&fila);
                break;
            default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
    system("pause");
	return 0;
}

