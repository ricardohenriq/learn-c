#include<stdio.h>
#include<stdlib.h>

/*
===================================
          PILHA DINAMICA
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
    ponteiro TOPO;
    int contador;
}Pilha_Dinamica;

/*
===========FUNCOES==========
Criar Pilha Vazia
Empilhar Elemento
Desempilhar Elemento
Ler Elemento
Exibir Elemento
===========FUNCOES==========
*/

void Criar_Pilha_Vazia(Pilha_Dinamica *pilha){
    pilha->TOPO = (ponteiro)malloc(sizeof(CAIXA));
    pilha->TOPO->proximo = NULL;
    pilha->contador = 0;
}

void Empilhar_Elemento(Pilha_Dinamica *pilha, Tipo_Pessoa pessoa){
    ponteiro auxiliar;
    auxiliar = (ponteiro)malloc(sizeof(CAIXA));
    auxiliar->pessoas = pessoa;
    auxiliar->proximo = pilha->TOPO->proximo;
    pilha->TOPO->proximo = auxiliar;
    pilha->contador++;
    printf("PESSOA EMPILHADA COM SUCESSO!\n");
}

void Desempilhar_Elemento(Pilha_Dinamica *pilha, Tipo_Pessoa *pessoa){
    ponteiro auxiliar;
    if(pilha->TOPO->proximo == NULL){
        printf("A PILHA ESTA VAZIA!\n");
    }else{
        auxiliar = pilha->TOPO->proximo;
        *pessoa = auxiliar->pessoas;
        pilha->TOPO->proximo = auxiliar->proximo;
        pilha->contador--;
        free(auxiliar);
        printf("PESSOA DESEMPILHADA COM SUCESSO!\n");
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

void Exibir_Pilha(Pilha_Dinamica *pilha){
    ponteiro auxiliar;
    auxiliar = pilha->TOPO->proximo;

    if(pilha->TOPO->proximo == NULL){
        printf("A PILHA ESTA VAZIA!\n");
    }else{
        while(auxiliar != NULL){
            Exibir_Pessoa(auxiliar->pessoas);
            auxiliar = auxiliar->proximo;
        }
    }
}

int main(){

    Pilha_Dinamica pilha;
	Tipo_Pessoa pessoa;
	int opcao;

    Criar_Pilha_Vazia(&pilha);

    do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Empilhar pessoa\n");
		printf("\t2 - Desempilhar pessoa\n");
		printf("\t3 - Exibir pilha (do TOPO a BASE)\n");
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
                Exibir_Pilha(&pilha);
                break;
            default:
				printf("OPCAO INVALIDA!\n");
		}
    }while(opcao!=0);
    system("pause");
    return 0;
}
