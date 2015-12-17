#include<stdio.h>
#include<stdlib.h>
/*
===================================
      ARVORE BINARIA DE BUSCA
===================================
*/

typedef struct{
	int codigo;//Codigo de pessoa //Chave Primaria
	//char nome[40];
	//char telRes[13]; //(__)____-____
	//char telCel[13]; //(__)____-____
}Tipo_Pessoa;

typedef struct nd{
    Tipo_Pessoa pessoas;
    struct nd *ESQUERDA, *DIREITA;
}NODO;

typedef NODO *Arvore_Binaria_Busca;

/*
===========FUNCOES==========
Criar Arvore Vazia
Ler Elemento
Inserir Elemento Na Arvore
Consultar Elemento
Exibir Elemento InOrdem
Exibir Elemento PosOrdem
Exibir Elemento PreOrdem
Remove Elemento com Sucessor Esquerdo(Maior dos Menores)
Sucessor Esquerdo(Maior dos Menores)
Remove Elemento com Sucessor Direito(Menor dos Maiores)
Sucessor Direito(Menor dos Maiores)
Menor valor da arvore
Maior valor da arvore
===========FUNCOES==========
*/

void Criar_Arvore_Vazia(Arvore_Binaria_Busca *arvore){
    *arvore=NULL;
}

void Inserir_Elemento_Arvore(Arvore_Binaria_Busca *arvore, Tipo_Pessoa pessoa){
    if((*arvore)==NULL){
        (*arvore)=(NODO *)malloc(sizeof(NODO));
        (*arvore)->ESQUERDA=NULL;
        (*arvore)->DIREITA=NULL;
        (*arvore)->pessoas=pessoa;
        printf("PESSOA INSERIDA COM SUCESSO!\n");
    }else if(pessoa.codigo<(*arvore)->pessoas.codigo){
        Inserir_Elemento_Arvore(&(*arvore)->ESQUERDA,pessoa);
    }else if(pessoa.codigo>(*arvore)->pessoas.codigo){
        Inserir_Elemento_Arvore(&(*arvore)->DIREITA,pessoa);
    }else{
        printf("JA EXISTE UMA PESSOA COM ESTE CODIGO! %d \n",pessoa.codigo);
    }
}

Tipo_Pessoa Sucessor_Esquerdo(Arvore_Binaria_Busca *arvore){

    Arvore_Binaria_Busca auxiliar;
    Tipo_Pessoa pessoa;
    auxiliar=(*arvore);

    while(auxiliar->DIREITA != NULL){
        auxiliar = auxiliar->DIREITA;
    }
    pessoa = auxiliar->pessoas;
    return (pessoa);
}

void Remover_Elemento_Maior_dos_Menores(Arvore_Binaria_Busca *arvore, Tipo_Pessoa *pessoa){

    Arvore_Binaria_Busca auxiliar_arvore;
    Tipo_Pessoa auxiliar_pessoa;

    if((*arvore) == NULL){
        printf("ELEMENTO NAO ENCONTRADO!\n");

    }else if((pessoa->codigo) < ((*arvore)->pessoas.codigo)){
        Remover_Elemento_Maior_dos_Menores(&(*arvore)->ESQUERDA,&(*pessoa));

    }else if((pessoa->codigo) > ((*arvore)->pessoas.codigo)){
        Remover_Elemento_Maior_dos_Menores(&(*arvore)->DIREITA,&(*pessoa));

    }else if((*arvore)->DIREITA == NULL){
        *pessoa = (*arvore)->pessoas;
        auxiliar_arvore = (*arvore);
        (*arvore) = (*arvore)->ESQUERDA;
        free(auxiliar_arvore);
        printf("ELEMENTO REMOVIDO!\n");

    }else if((*arvore)->ESQUERDA == NULL){
        (*pessoa) = (*arvore)->pessoas;
        auxiliar_arvore = (*arvore);
        (*arvore) = (*arvore)->DIREITA;
        free(auxiliar_arvore);
        printf("ELEMENTO REMOVIDO!\n");

    }else{
        (*pessoa) = (*arvore)->pessoas;
        (*arvore)->pessoas = Sucessor_Esquerdo(&(*arvore)->ESQUERDA);
        auxiliar_pessoa = (*arvore)->pessoas;
        Remover_Elemento_Maior_dos_Menores(&(*arvore)->ESQUERDA,&auxiliar_pessoa);
    }
}

void Consulta_Elemento(Arvore_Binaria_Busca arvore, Tipo_Pessoa pessoa){
    if(arvore==NULL){
        printf("ELEMENTO NAO ENCONTRADO!\n");
    }else if(pessoa.codigo < arvore->pessoas.codigo){
        Consulta_Elemento(arvore->ESQUERDA,pessoa);
    }else if(pessoa.codigo > arvore->pessoas.codigo){
        Consulta_Elemento(arvore->DIREITA,pessoa);
    }else{
        Exibir_Pessoa(arvore->pessoas);
    }
}

void Exibir_Pessoa(Tipo_Pessoa pessoa){
	printf("Codigo:\t\t%d\n", pessoa.codigo);
	//printf("Nome:\t\t%s\n", pessoa.nome);
	//printf("Tel. Res:\t%s\n", pessoa.telRes);
	//printf("Tel. Cel:\t%s\n\n", pessoa.telCel);
}

void Exibir_PreOrdem(Arvore_Binaria_Busca arvore){
    if(arvore!=NULL){
        Exibir_Pessoa(arvore->pessoas);
        Exibir_PreOrdem(arvore->ESQUERDA);
        Exibir_PreOrdem(arvore->DIREITA);
    }
}

void Exibir_InOrdem(Arvore_Binaria_Busca arvore){
    if(arvore!=NULL){
        Exibir_InOrdem(arvore->ESQUERDA);
        Exibir_Pessoa(arvore->pessoas);
        Exibir_InOrdem(arvore->DIREITA);
    }
}

void Exibir_PosOrdem(Arvore_Binaria_Busca arvore){
    if(arvore!=NULL){
        Exibir_PosOrdem(arvore->ESQUERDA);
        Exibir_PosOrdem(arvore->DIREITA);
        Exibir_Pessoa(arvore->pessoas);
    }
}

void Ler_Elemento(Tipo_Pessoa *pessoa){
	printf("Informe o codigo da pessoa: ");
	scanf("%d*c", &pessoa->codigo);
	/*getchar();
	printf("Informe o nome da pessoa: ");
	scanf("%[^\n]",&pessoa->nome);
	getchar();
	printf("Informe o telefone residencial: ");
	scanf("%[^\n]",&pessoa->telRes);
	getchar();
	printf("Informe o telefone celular: ");
	scanf("%[^\n]",&pessoa->telCel);
	*/
}

/*
Tipo_Pessoa Sucessor_Direito(Arvore_Binaria_Busca *arvore){

    Arvore_Binaria_Busca auxiliar;
    Tipo_Pessoa pessoa;
    auxiliar=(*arvore);

    while(auxiliar->ESQUERDA != NULL){
        auxiliar = auxiliar->ESQUERDA;
    }
    pessoa = auxiliar->pessoas;
    return (pessoa);
}

void Remover_Elemento_Menor_Dos_Maiores(Arvore_Binaria_Busca *arvore, Tipo_Pessoa *pessoa){

    Arvore_Binaria_Busca auxiliar_arvore;
    Tipo_Pessoa auxiliar_pessoa;

    if((*arvore) == NULL){
        printf("ELEMENTO NAO ENCONTRADO!\n");

    }else if((pessoa->codigo) < ((*arvore)->pessoas.codigo)){
        Remover_Elemento_Menor_Dos_Maiores(&(*arvore)->ESQUERDA,&(*pessoa));

    }else if((pessoa->codigo) > ((*arvore)->pessoas.codigo)){
        Remover_Elemento_Menor_Dos_Maiores(&(*arvore)->DIREITA,&(*pessoa));

    }else if((*arvore)->DIREITA == NULL){
        *pessoa = (*arvore)->pessoas;
        auxiliar_arvore = (*arvore);
        (*arvore) = (*arvore)->ESQUERDA;
        free(auxiliar_arvore);
        printf("ELEMENTO REMOVIDO!\n");

    }else if((*arvore)->ESQUERDA == NULL){
        (*pessoa) = (*arvore)->pessoas;
        auxiliar_arvore = (*arvore);
        (*arvore) = (*arvore)->DIREITA;
        free(auxiliar_arvore);
        printf("ELEMENTO REMOVIDO!\n");

    }else{
        (*pessoa) = (*arvore)->pessoas;
        (*arvore)->pessoas = Sucessor_Direito(&(*arvore)->DIREITA);
        auxiliar_pessoa = (*arvore)->pessoas;
        Remover_Elemento_Menor_Dos_Maiores(&(*arvore)->DIREITA,&auxiliar_pessoa);
    }
}
*/

void Menor_Elemento(Arvore_Binaria_Busca *arvore){

    Arvore_Binaria_Busca auxiliar;
    auxiliar = (*arvore);

    while(auxiliar->ESQUERDA != NULL){
        auxiliar = auxiliar->ESQUERDA;
    }
    Exibir_Pessoa(auxiliar->pessoas);
}

void Maior_Elemento(Arvore_Binaria_Busca *arvore){

    Arvore_Binaria_Busca auxiliar;
    auxiliar = (*arvore);

    while(auxiliar->DIREITA != NULL){
        auxiliar = auxiliar->DIREITA;
    }
    Exibir_Pessoa(auxiliar->pessoas);
}

void Procura_Sucessor_Elemento(Arvore_Binaria_Busca arvore, Tipo_Pessoa pessoa){

    static int flag = 0;//Recebera 1 quando encontrar o primeiro numero maior que o digitado pelo usuario
    if(arvore!=NULL){
        if((arvore->pessoas.codigo > pessoa.codigo) && (flag == 0)){
            flag = 1;
            Exibir_Pessoa(arvore->pessoas);
        }
        Procura_Sucessor_Elemento(arvore->ESQUERDA, pessoa);
        Procura_Sucessor_Elemento(arvore->DIREITA, pessoa);
    }
}

int main(){

    Arvore_Binaria_Busca arvore;
    Tipo_Pessoa pessoa;
    int opcao;

    Criar_Arvore_Vazia(&arvore);

    do{
		printf("Selecione uma opcao:\n");
		printf("\t1 - Inserir uma pessoa na lista\n");
		printf("\t2 - Excluir uma pessoa da lista\n");
		printf("\t3 - Mostrar lista PreOrdem\n");
		printf("\t4 - Mostrar lista InOrdem\n");
		printf("\t5 - Mostrar lista PosOrdem\n");
		printf("\t6 - Consultar Elemento\n");
		printf("\t7 - Consultar MENOR Elemento\n");
		printf("\t8 - Consultar MAIOR Elemento\n");
		printf("\t9 - Consultar sucessor de um Elemento\n");
		printf("\t0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				break;
			case 1:
				Ler_Elemento(&pessoa);
				Inserir_Elemento_Arvore(&arvore, pessoa);
				break;
			case 2:
				printf("INFORME O CODIGO DO ELEMENTO: ");
				scanf("%d", &pessoa.codigo);
				Remover_Elemento_Maior_dos_Menores(&arvore, &pessoa);
				//Remover_Elemento_Menor_Dos_Maiores(&arvore, &pessoa);
				break;
			case 3:
				Exibir_PreOrdem(arvore);
				break;
 			case 4:
				Exibir_InOrdem(arvore);
				break;
            case 5:
				Exibir_PosOrdem(arvore);
				break;
            case 6:
                printf("INFORME O CODIGO DO ELEMENTO: ");
				scanf("%d", &pessoa.codigo);
				Consulta_Elemento(arvore,pessoa);
				break;
            case 7:
                printf("Menor Elemento\n");
                Menor_Elemento(&arvore);
                break;
            case 8:
                printf("Menor Elemento\n");
                Maior_Elemento(&arvore);
                break;
            case 9:
                printf("Digite um elemento a ser encontrado na Arvore: ");
                scanf("%d", &pessoa.codigo);
                Procura_Sucessor_Elemento(arvore,pessoa);
                break;
			default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
	system("pause");
	return 0;
}
