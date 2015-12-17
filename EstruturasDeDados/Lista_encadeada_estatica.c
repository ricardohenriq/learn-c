#include <stdio.h>
#include <stdlib.h>
#define MAXL 100
//MAXL e o tamanho
//da Lista Estatica

/*
===================================
     LISTA ENCADEADA ESTATICA
===================================
*/

//FUNÇAO BUSCAR ELEMENTO NAO ESTA FUNCIONANDO

typedef struct{
	int codigo;//Codigo de pessoa //Chave primaria
	char nome[40];
	char telRes[13]; //(__)____-____
	char telCel[13]; //(__)____-____
	int proximo;
}Tipo_Pessoa;

typedef struct{
    Tipo_Pessoa pessoas[MAXL];
    int primeiro,ultimo,disponivel;
    int contador;
}Lista_Encadeada_Estatica;

/*
===========FUNCOES==========
Criar Lista Vazia
Ler Elemento
Inserir Pessoa Na Lista
Remover Pessoa Da Lista
Exibir Lista
===========FUNCOES==========
*/

void Criar_Lista_Vazia(Lista_Encadeada_Estatica *lista){
    int i;//Auxiliar para preenchimento do proximo
    lista->primeiro=-1;
    lista->ultimo=-1;
    lista->disponivel=0;
    for(i=0;i<MAXL;i++){
        lista->pessoas[i].proximo=i+1;
    }
    lista->pessoas[i].proximo=-1;
}

void Inserir_Pessoa_Lista(Lista_Encadeada_Estatica *lista, Tipo_Pessoa pessoa){

    int auxiliar_disponivel;
    int auxiliar_primeiro;
    int auxiliar_que_recebe_auxiliar_primeiro;

    if(lista->disponivel == -1){
        printf("A LISTA ESTA CHEIA!\n");
    }else{
        auxiliar_disponivel = lista->disponivel;
        lista->disponivel = lista->pessoas[auxiliar_disponivel].proximo;
        lista->pessoas[auxiliar_disponivel] = pessoa;
        auxiliar_primeiro = lista->primeiro;

        if(auxiliar_primeiro == (-1)){
            lista->pessoas[auxiliar_disponivel].proximo=lista->primeiro;
            lista->primeiro=auxiliar_disponivel;
            lista->ultimo=auxiliar_disponivel;

        }else if(auxiliar_primeiro==lista->ultimo){
            if(lista->pessoas[auxiliar_primeiro].codigo < pessoa.codigo){
                lista->pessoas[auxiliar_disponivel].proximo=lista->pessoas[auxiliar_primeiro].proximo;
                lista->pessoas[auxiliar_primeiro].proximo=auxiliar_disponivel;
                lista->ultimo=auxiliar_disponivel;

            }else{
                lista->pessoas[auxiliar_disponivel].proximo=auxiliar_primeiro;
                lista->primeiro=auxiliar_disponivel;
            }
        }else{
            while((auxiliar_primeiro != (-1)) && (pessoa.codigo > lista->pessoas[auxiliar_primeiro].codigo)){
                auxiliar_que_recebe_auxiliar_primeiro=auxiliar_primeiro;
                auxiliar_primeiro=lista->pessoas[auxiliar_primeiro].proximo;
            }

            if(auxiliar_primeiro == lista->primeiro){
                lista->pessoas[auxiliar_disponivel].proximo = lista->primeiro;
                lista->primeiro = auxiliar_disponivel;

            }else{
                lista->pessoas[auxiliar_disponivel].proximo = auxiliar_primeiro;
                lista->pessoas[auxiliar_que_recebe_auxiliar_primeiro].proximo = auxiliar_disponivel;

                if(auxiliar_primeiro == (-1)){
                    lista->ultimo = auxiliar_disponivel;
                }

            }
        }
        printf("PESSOA INSERIDA NA LISTA COM SUCESSO!\n");
    }
}

void Remover_Elemento(Lista_Encadeada_Estatica *lista, Tipo_Pessoa *pessoa){

    int auxiliar_primeiro;
    int auxiliar_que_recebe_auxiliar_primeiro;

    if(lista->primeiro == -1){
        printf("A LISTA ESTA CHEIA!\n");
    }else{
        auxiliar_primeiro = lista->primeiro;
        while((auxiliar_primeiro!=-1)&& (pessoa->codigo > lista->pessoas[auxiliar_primeiro].codigo)){
            auxiliar_que_recebe_auxiliar_primeiro = auxiliar_primeiro;
            auxiliar_primeiro=lista->pessoas[auxiliar_primeiro].proximo;
            if((auxiliar_primeiro==-1)||(pessoa->codigo != lista->pessoas[auxiliar_primeiro].codigo)){
                printf("PESSOA NAO ENCONTRADA!\n");
            }else{
                //pessoa=lista->pessoas[auxiliar_primeiro];
                *pessoa=lista->pessoas[auxiliar_primeiro];
                if(lista->primeiro==lista->ultimo){
                    lista->primeiro=-1;
                    lista->ultimo=-1;
                    lista->pessoas[auxiliar_primeiro].proximo=lista->disponivel;
                    lista->disponivel = auxiliar_primeiro;
                }else{
                    if(auxiliar_primeiro == lista->ultimo){
                        lista->ultimo = auxiliar_que_recebe_auxiliar_primeiro;
                        lista->pessoas[auxiliar_que_recebe_auxiliar_primeiro].proximo=lista->pessoas[auxiliar_primeiro].proximo;
                        lista->pessoas[auxiliar_primeiro].proximo = lista->disponivel;
                        lista->disponivel = auxiliar_primeiro;
                    }else if(auxiliar_primeiro == lista->primeiro){
                        lista->primeiro = lista->pessoas[auxiliar_primeiro].proximo;
                        lista->pessoas[auxiliar_primeiro].proximo = lista->disponivel;
                        lista->disponivel = auxiliar_primeiro;
                    }else{
                        lista->pessoas[auxiliar_que_recebe_auxiliar_primeiro].proximo = lista->pessoas[auxiliar_primeiro].proximo;
                        lista->pessoas[auxiliar_primeiro].proximo = lista->disponivel;
                        lista->disponivel = auxiliar_primeiro;
                    }
                }
            }
        }
    }
}

void Buscar_Elemento(Lista_Encadeada_Estatica lista, int codigo){

    int auxiliar_primeiro;
    int auxiliar_que_recebe_auxiliar_primeiro = -1;

    if(lista.primeiro == -1){
        printf("A LISTA ESTA VAZIA!\n");
    }else{
        auxiliar_primeiro = lista.primeiro;
        while((auxiliar_primeiro != -1)&&(codigo > lista.pessoas[auxiliar_primeiro].codigo)){
            auxiliar_primeiro = lista.pessoas[auxiliar_primeiro].proximo;
            if(codigo == lista.pessoas[auxiliar_primeiro].codigo){
                auxiliar_que_recebe_auxiliar_primeiro = auxiliar_primeiro;
                printf("PESSOA ENCONTRADA!\n");
            }else{
                printf("PESSOA NAO ENCONTRADA!\n");
            }
        }
    }
}

void Exibir_Pessoa(Tipo_Pessoa pessoa){
	printf("Codigo:\t\t%d\n", pessoa.codigo);
	printf("Nome:\t\t%s\n", pessoa.nome);
	printf("Tel. Res:\t%s\n", pessoa.telRes);
	printf("Tel. Cel:\t%s\n\n", pessoa.telCel);
}

void Exibir_Lista(Lista_Encadeada_Estatica lista){

    int auxiliar_primeiro;

    if(lista.primeiro == -1){
        printf("A LISTA ESTA VAZIA!\n");
    }else{
        auxiliar_primeiro = lista.primeiro;
        while(auxiliar_primeiro != -1){
            Exibir_Pessoa(lista.pessoas[auxiliar_primeiro]);
            auxiliar_primeiro = lista.pessoas[auxiliar_primeiro].proximo;
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

int main(){

    Lista_Encadeada_Estatica lista;
    Tipo_Pessoa pessoa;
    Criar_Lista_Vazia(&lista);
    int opcao;

    do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Inserir uma pessoa na lista\n");
		printf("\t2 - Excluir uma pessoa da lista\n");
        printf("\t3 - Pesquisar uma pessoa na lista\n");
        printf("\t4 - Mostrar lista\n");
        printf("\t0 - Sair\n");
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
                Remover_Elemento(&lista,&pessoa);
                break;
            case 3:
                printf("INFORME O CODIGO DA PESSOA: ");
				scanf("%d", &pessoa.codigo);
                Buscar_Elemento(lista,pessoa.codigo);
                break;
            case 4:
                Exibir_Lista(lista);
                break;
            default:
                printf("OPCAO INVALIDA!\n");
        }
    }while(opcao!=0);
    system("pause");
    return 0;
}