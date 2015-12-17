#include<stdio.h>
#include<stdlib.h>

/*
===================================
     LISTA ENCADEADA DINAMICA
===================================
*/


typedef struct{
	int codigo;//Codigo de pessoa //Chave primaria
	char nome[40];
	char telRes[13]; //(__)____-____
	char telCel[13]; //(__)____-____
	int proximo;
}Tipo_Pessoa;

typedef struct cx{
    Tipo_Pessoa pessoas;
    struct cx *proximo;
}CAIXA;

typedef CAIXA *ponteiro;

typedef struct{
    ponteiro primeiro, ultimo;
    int contador;
}Lista_Encadeada_Dinamica;

/*
===========FUNCOES==========
Criar Lista Vazia
Ler Elemento
Inserir Pessoa Na Lista
Remover Pessoa Da Lista
Exibir Lista
===========FUNCOES==========
*/

void Criar_Lista_Vazia(Lista_Encadeada_Dinamica *lista){
    lista->primeiro = (ponteiro)malloc(sizeof(CAIXA));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL;
    lista->contador = 0;
}

int Verificar_Lista_Vazia(Lista_Encadeada_Dinamica lista){
    return(lista.primeiro == lista.ultimo);
}

void Inserir_Pessoa_Lista(Lista_Encadeada_Dinamica *lista, Tipo_Pessoa pessoa){

    ponteiro auxiliar_1;
    ponteiro auxiliar_2;
    // p = auxiliar_1
    // a = auxiliar_2

    auxiliar_1 = (ponteiro)malloc(sizeof(CAIXA));
    auxiliar_1->pessoas = pessoa;
    auxiliar_2 = lista->primeiro;
    while((auxiliar_2 != lista->ultimo) && (pessoa.codigo > auxiliar_2->proximo->pessoas.codigo)){
        auxiliar_2 = auxiliar_2->proximo;
    }
    if (auxiliar_2 == lista->ultimo){
        auxiliar_1->proximo = auxiliar_2->proximo;
        auxiliar_2->proximo = auxiliar_1;
        lista->ultimo = auxiliar_1;
        printf("PESSOA INSERIDA NA LISTA COM SUCESSO!\n");
    }else if (pessoa.codigo == auxiliar_2->proximo->pessoas.codigo){
        printf("ELEMENTO JA CADASTRADO NA LISTA!\n");
        free(auxiliar_1);
        lista->contador--;
    }else{
        auxiliar_1->proximo = auxiliar_2->proximo;
        auxiliar_2->proximo = auxiliar_1;
        printf("PESSOA INSERIDA NA LISTA COM SUCESSO!\n");
    }
    lista->contador++;
}
void Remover_Elemento_Lista(Lista_Encadeada_Dinamica *lista, Tipo_Pessoa pessoa){

    ponteiro auxiliar_1;
    ponteiro auxiliar_2;

    if (Verificar_Lista_Vazia(*lista)){
        printf("A LISTA ESTA VAZIA!\n");
    }
    else{
        auxiliar_2 = lista->primeiro;
        while((auxiliar_2 != lista->ultimo) && (pessoa.codigo > auxiliar_2->proximo->pessoas.codigo)){
            auxiliar_2 = auxiliar_2->proximo;
        }
        if((auxiliar_2 == lista->ultimo)||(pessoa.codigo != auxiliar_2->proximo->pessoas.codigo)){
            printf("ELEMENTO NAO ENCONTRADO!\n");
        }else{
            auxiliar_1 = auxiliar_2->proximo;
            pessoa = auxiliar_1->pessoas;
            auxiliar_2->proximo = auxiliar_1->proximo;
            if(auxiliar_1 == lista->ultimo){
                lista->ultimo = auxiliar_2;
            }
            free(auxiliar_1);
            lista->contador--;
        }
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

void Exibir_Lista(Lista_Encadeada_Dinamica *lista){
    ponteiro auxiliar;
    auxiliar = lista->primeiro->proximo;
    if (Verificar_Lista_Vazia(*lista)){
        printf("A LISTA ESTA VAZIA!\n");
    }else{
        while(auxiliar != NULL){
            Exibir_Pessoa(auxiliar->pessoas);
            auxiliar = auxiliar->proximo;
        }
    }
}

int main(){
    Lista_Encadeada_Dinamica lista;
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
        scanf("%d*c", &opcao);
        switch(opcao){
            case 0:
                break;
            case 1:
                Ler_Pessoa(&pessoa);
                Inserir_Pessoa_Lista(&lista,pessoa);
                break;
            case 2:
                printf("INFORME O CODIGO DA PESSOA: ");
				scanf("%d", &pessoa.codigo);
                Remover_Elemento_Lista(&lista,pessoa);
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
