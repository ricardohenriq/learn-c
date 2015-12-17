#include<stdio.h>
#include<stdlib.h>
#define MAXP 100
//MAXP e o tamanho
//da Pilha Estatica
#define MAXF 100
//MAXF e o tamanho
//da Fila Estatica

/*
===================================
 PILHA ESTATICA COM FILA ESTATICA
===================================
*/

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

typedef struct{
	Tipo_Pessoa pessoas[MAXF];
	int inicio, fim;
	int contador;
}Fila_Estatica;

/* ====== FUNCOES COMUNS A PILHA E FILA ======*/

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

void Exibir_Pessoa(Tipo_Pessoa pessoa){
	printf("Codigo:\t\t%d\n", pessoa.codigo);
	printf("Nome:\t\t%s\n", pessoa.nome);
	printf("Tel. Res:\t%s\n", pessoa.telRes);
	printf("Tel. Cel:\t%s\n\n", pessoa.telCel);
}

/* ====== FUNCOES COMUNS A PILHA E FILA ======*/

/* ========== FUNCOES COMUNS A PILHA ==========*/

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

void Mostrar_Informacoes_Pessoa_Pilha(Pilha_Estatica *pilha, Tipo_Pessoa pessoa){

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

/* ========== FUNCOES COMUNS A PILHA ==========*/

/* ========== FUNCOES COMUNS A FILA ==========*/

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

void Mostrar_Informacoes_Pessoa_Fila(Fila_Estatica *fila, Tipo_Pessoa pessoa){

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

/* ========== FUNCOES COMUNS A FILA ==========*/

/* ========== FUNCOES DE MANIPULACAO ==========*/

void Inverter_Pilha(Pilha_Estatica pilha, Pilha_Estatica *pilha_invetida){

    if(Verificar_Pilha_Vazia(pilha)){
		printf("A PILHA QUE DESEJA INVERTER ESTA VAZIA!\n");
	}else{
	    while(pilha.TOPO > 0){
            pilha_invetida->pessoas[pilha_invetida->TOPO] = pilha.pessoas[pilha.TOPO-1];
            pilha_invetida->TOPO++;
            pilha.TOPO--;
	    }
	}
}

void Duplicar_Pilha(Pilha_Estatica pilha, Pilha_Estatica *pilha_duplicada){

    Pilha_Estatica pilha_auxiliar;//usada para servir como intermediaria
    //para duplicacao
    Criar_Pilha_Vazia(&pilha_auxiliar);

    if(Verificar_Pilha_Vazia(pilha)){
		printf("A PILHA QUE DESEJA DUPLICAR ESTA VAZIA!\n");
	}else{
	    while(pilha.TOPO > 0){
            pilha_auxiliar.pessoas[pilha_auxiliar.TOPO] = pilha.pessoas[pilha.TOPO-1];
            pilha_auxiliar.TOPO++;
            pilha.TOPO--;
	    }
	    while(pilha_auxiliar.TOPO > 0){
            pilha_duplicada->pessoas[pilha_duplicada->TOPO] = pilha_auxiliar.pessoas[pilha_auxiliar.TOPO-1];
            pilha_duplicada->TOPO++;
            pilha_auxiliar.TOPO--;
	    }
	}
}

void Duplicar_Fila(Fila_Estatica fila, Fila_Estatica *fila_duplicada){

    int contador_posicoes;//Posicoes do VETOR

    if(fila.fim == fila.inicio){
		printf("A FILA QUE DESEJA DUPLICAR ESTA VAZIA!\n");
	}else{
	    for(contador_posicoes = fila.inicio; contador_posicoes < fila.fim; contador_posicoes++){
            fila_duplicada->pessoas[contador_posicoes] = fila.pessoas[contador_posicoes];
            fila_duplicada->fim = (fila_duplicada->fim+1)%MAXF;
            fila_duplicada->contador++;
        }
	}
}

void Inverter_Fila(Fila_Estatica fila, Fila_Estatica *fila_invertida){

    int contador_posicoes;//Posicoes do VETOR
    Pilha_Estatica pilha_auxiliar;//usada para servir como intermediaria
    //para duplicacao
    Criar_Pilha_Vazia(&pilha_auxiliar);

    if(fila.fim == fila.inicio){
		printf("A FILA QUE DESEJA INVERTER ESTA VAZIA!\n");
	}else{
	    for(contador_posicoes = fila.inicio; contador_posicoes < fila.fim; contador_posicoes++){
            pilha_auxiliar.pessoas[pilha_auxiliar.TOPO] = fila.pessoas[contador_posicoes];
            pilha_auxiliar.TOPO++;
        }
       while(pilha_auxiliar.TOPO > 0){
            fila_invertida->pessoas[fila_invertida->fim] = pilha_auxiliar.pessoas[pilha_auxiliar.TOPO-1];
            fila_invertida->fim = (fila_invertida->fim+1)%MAXF;
            fila_invertida->contador++;
            pilha_auxiliar.TOPO--;

	    }
	}
}

/* ========== FUNCOES DE MANIPULACAO ==========*/


int main(){

    Pilha_Estatica pilha;
    Pilha_Estatica pilha_invertida;
    Pilha_Estatica pilha_duplicada;
    Criar_Pilha_Vazia(&pilha);
    Criar_Pilha_Vazia(&pilha_invertida);
    Criar_Pilha_Vazia(&pilha_duplicada);

    Fila_Estatica fila;
    Fila_Estatica fila_invertida;
    Fila_Estatica fila_duplicada;
    Criar_Fila_Vazia(&fila);
    Criar_Fila_Vazia(&fila_invertida);
    Criar_Fila_Vazia(&fila_duplicada);

	Tipo_Pessoa pessoa;

	int opcao;

	do{
		printf("Selecione uma opcao:\n");
		printf("Usando Pilha Estatica\n");
		printf("\t1 - Empilhar pessoa\n");
		printf("\t2 - Desempilhar pessoa\n");
		printf("\t3 - Mostrar informacoes de uma pessoa\n");
		printf("\t4 - Exibir pilha (do TOPO a BASE)\n");
		printf("Usando Fila Estatica\n");
		printf("\t5 - Enfileirar uma pessoa\n");
		printf("\t6 - Desenfileirar uma pessoa\n");
		printf("\t7 - Mostrar informacoes de uma pessoa\n");
		printf("\t8 - Exibir fila (do PRIMEIRO para o ULTIMO)\n");
		printf("Usando Ambas\n");
		printf("\t9 - Inverter pilha\n");
		printf("\t10 - Exibir pilha invertida (do TOPO a BASE)\n");
		printf("\t11 - Duplicar pilha\n");
		printf("\t12 - Exibir pilha duplicada (do TOPO a BASE)\n");
		printf("\t13 - Duplicar fila\n");
		printf("\t14 - Exibir fila Duplicada (do PRIMEIRO para o ULTIMO)\n");
		printf("\t15 - Inverter fila\n");
		printf("\t16 - Exibir fila invertida (do PRIMEIRO para o ULTIMO)\n");
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
                Mostrar_Informacoes_Pessoa_Pilha(&pilha, pessoa);
				break;
			case 4:
                Exibir_Pilha(&pilha);
				break;
            case 5:
				Ler_Pessoa(&pessoa);
				Enfileirar_Elemento(&fila, pessoa);
				break;
			case 6:
				Desenfileirar_Elemento(&fila, &pessoa);
				break;
			case 7:
                Mostrar_Informacoes_Pessoa_Fila(&fila, pessoa);
				break;
			case 8:
                Exibir_Fila(&fila);
				break;
            case 9:
                Inverter_Pilha(pilha, &pilha_invertida);
                Ler_Pessoa(&pessoa);
				Empilhar_Elemento(&pilha_invertida, pessoa);
				Ler_Pessoa(&pessoa);
				Empilhar_Elemento(&pilha_invertida, pessoa);
                break;
            case 10:
                Exibir_Pilha(&pilha_invertida);
				break;
            case 11:
                Duplicar_Pilha(pilha, &pilha_duplicada);
                Ler_Pessoa(&pessoa);
				Empilhar_Elemento(&pilha_duplicada, pessoa);
				Ler_Pessoa(&pessoa);
				Empilhar_Elemento(&pilha_duplicada, pessoa);
                break;
            case 12:
                Exibir_Pilha(&pilha_duplicada);
				break;
            case 13:
                Duplicar_Fila(fila, &fila_duplicada);
                break;
            case 14:
                Exibir_Fila(&fila_duplicada);
				break;
            case 15:
                Inverter_Fila(fila, &fila_invertida);
                break;
            case 16:
                Exibir_Fila(&fila_invertida);
				break;
			default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
    system("pause");
	return 0;
}
