#include<stdio.h>
#include<stdlib.h>
#define COLUNA 3
#define LINHA 1
#define MAXL COLUNA*LINHA
//MAXL e o tamanho
//da Lista Estatica
//Por consequencia
//a quantidade de
//acentos do TEATRO

/*
=======================================
TEATRO USANDO LISTA SEQUENCIAL ESTATICA
=======================================
*/

typedef struct{
	int coluna_teatro;
	int linha_teatro;
	int RG;//RG da pessoa
	int condicao;//Se  comprou ou reservou a cadeira
	char nome[40];
	char telRes[13]; //(__)____-____
}Tipo_Pessoa;

typedef struct{
    Tipo_Pessoa pessoas[MAXL];
    int primeiro,ultimo;
    int MAT[LINHA][COLUNA];
}Lista_Sequencial_Estatica;
/* Lista_Sequencial_Estatica[30] PORQUE E UMA PEÇA POR DIA */

void Criar_Teatro_Vazio(Lista_Sequencial_Estatica *TEATRO){
	TEATRO->primeiro = 0;
	TEATRO->ultimo = 0;
	int i,j;//auxiliar pra preenchemento

    for(i = 0;i < LINHA; i++){
        for(j = 0; j < (COLUNA + 1); j++){
            TEATRO->MAT[i][j] = 0;//iniciando LIVRE
        }
    }
}

int Verificar_Teatro_Cheio(Lista_Sequencial_Estatica *TEATRO){
	return (TEATRO->ultimo == MAXL);//menos o corredor
}

int Verificar_Teatro_Vazio(Lista_Sequencial_Estatica *TEATRO){
	return (TEATRO->ultimo == TEATRO->primeiro);
}

void Exibir_Teatro(Lista_Sequencial_Estatica *TEATRO){

    int contador_posicoes = 0;
    int i,j;//auxiliar pra preenchimento
    system("cls");
    printf("\n\n");
	printf("\n   +++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n   |                                                 |");
	printf("\n   |                    P A L C O                    |");
	printf("\n   |                                                 |");
	printf("\n   +++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\n");

     if(Verificar_Teatro_Vazio(TEATRO)){
        printf("\n   |++++++++++++++++++ TEATRO VAZIO +++++++++++++++++|");
        printf("\n\n");

    }else if(Verificar_Teatro_Cheio(TEATRO)){
        printf("\n   |+++++++++++++++++ TEATRO LOTADO +++++++++++++++++|");
        printf("\n\n");
    }else{
        /*=============== IMPRIMINDO GUIAS SUPERIORES ===============*/
        printf("   ");//para manter um alinhamento mais afastado da guia
        for(i = (COLUNA/2);i > 0; i--){
            //(COLUNA/2) porque o teatro e divido no meio pelo corredor
            //Lado esquerdo = negativo Lado direito = positivo
            printf("  -");
            printf("%d",i);
        }
        printf("   0");
        for(i = 1;i <= (COLUNA/2); i++){

            //(COLUNA/2) porque o teatro e divido no meio pelo corredor
            //Lado esquerdo = negativo Lado direito = positivo
            printf("  +");
            printf("%d",i);
        }
        printf("\n");
        /*=============== IMPRIMINDO GUIAS SUPERIORES ===============*/

        /*=============== IMPRIMINDO CONTEUDO DO TATRO ===============*/

        for(i = 0; i < LINHA; i++){
        /*=============== IMPRIMINDO GUIAS LATERAIS ===============*/
                if(i<9){
                    //porque la em baixo eu somarei 1 ao j
                    printf("   0%d",(i+1));
                }//para manter um alinhamento
                else{
                    printf("  %d",(i+1));
                }
        /*=============== IMPRIMINDO GUIAS LATERAIS ===============*/
            for(j = 0; j < COLUNA;j++){

                if(j == (COLUNA/2)){
                    printf("|C|");
                    printf(" ");
                }
                if((TEATRO->MAT[i][j] == 0)&&(j != (COLUNA/2))){
                    printf("|L|");
                    printf(" ");
                }
                else if((TEATRO->MAT[i][j] == 1)&&(j != (COLUNA/2))){
                    printf("|R|");
                    printf(" ");
                }else if((TEATRO->MAT[i][j] == 2)&&(j != (COLUNA/2))){
                    printf("|O|");
                    printf(" ");
                }
                contador_posicoes++;
                if((contador_posicoes%COLUNA)==0 ){
                    printf("\n");
                }
            }
        }
    }
}

void Ler_Pessoa(Lista_Sequencial_Estatica *TEATRO,Tipo_Pessoa *pessoa){

    int coluna_auxiliar = 0;
    int linha_auxiliar = 0;
    int auxiliar = 0;//Se setar 1 caso o usuario tente comprar uma cadeira no
    //corredor antes que o teatro esteja cheio
    inicio:do{
        system("cls");
        printf("Informe a coluna e a linha onde deseja sentar-se\n ");
        printf("da seguinte forma (2 3)\n");
        scanf("%d %d",&linha_auxiliar,&coluna_auxiliar);
        fflush(stdin);
        auxiliar = 0;
        if((coluna_auxiliar == 0)&&(TEATRO->ultimo < MAXL - LINHA)){
            printf("Este local so pede ser vendido quando\n");
            printf("o teatro estiver cheio.\n");
            auxiliar = 1;
        }

    }while ( (coluna_auxiliar < -(COLUNA/2))||(auxiliar == 1)||((coluna_auxiliar > COLUNA/2)||(linha_auxiliar < 1)||(linha_auxiliar > LINHA + 2)));
    linha_auxiliar = linha_auxiliar - 1;
    coluna_auxiliar = coluna_auxiliar + COLUNA/2 ;
    if((TEATRO->MAT[linha_auxiliar][coluna_auxiliar] == 2)||(TEATRO->MAT[linha_auxiliar][coluna_auxiliar] == 1)){
        printf("Este local esta ocupado.\n");
        goto inicio;
    }
    do{
        getchar();
        printf("Informe se deseja (COMPRAR | 2) ou (RESERVAR | 1): ");
        scanf("%d*c",&pessoa->condicao);
    }while((pessoa->condicao != 2)&&(pessoa->condicao != 1));
	TEATRO->MAT[linha_auxiliar][coluna_auxiliar] = pessoa->condicao;

    pessoa->coluna_teatro = coluna_auxiliar;
    pessoa->linha_teatro = linha_auxiliar;
    coluna_auxiliar = 0;
    linha_auxiliar = 0;
    do{
        getchar();
        printf("Informe o RG da pessoa: ");
        scanf("%d*c",&pessoa->RG);
    }while(pessoa->RG < 0);
	getchar();
	fflush(stdin);
	printf("Informe o nome da pessoa: ");
	scanf("%[^\n]",&pessoa->nome);
    getchar();
    fflush(stdin);
    printf("Informe o telefone residencial: ");
    scanf("%[^\n]",&pessoa->telRes);
}

void Inserir_Pessoa_Lista(Lista_Sequencial_Estatica *TEATRO, Tipo_Pessoa pessoa){
	int Indice_Lista; // Usada para percorrer a lista de pessoas
	int Indice_Pessoa; // Usada para organizar as pessoas na lista
	if(Verificar_Teatro_Cheio(TEATRO)){
		printf("O TEATRO ESTA CHEIO!\n");
	}else{
		for(Indice_Lista = TEATRO->primeiro; (Indice_Lista!=TEATRO->ultimo) && (pessoa.RG > TEATRO->pessoas[Indice_Lista].RG); Indice_Lista++);
		if(Indice_Lista == TEATRO->ultimo){
			TEATRO->pessoas[Indice_Lista] = pessoa;
			TEATRO->ultimo++;
		}else{
			for(Indice_Pessoa = TEATRO->ultimo; Indice_Pessoa > Indice_Lista; Indice_Pessoa--){
				TEATRO->pessoas[Indice_Pessoa] = TEATRO->pessoas[Indice_Pessoa-1];
			}
			TEATRO->pessoas[Indice_Lista] = pessoa;
			TEATRO->ultimo++;
		}
		system("cls");
		printf("PESSOA INSERIDA NA LISTA COM SUCESSO!\n");
	}
}

void Remover_Pessoa_Lista(Lista_Sequencial_Estatica *TEATRO, Tipo_Pessoa *pessoa, int coluna_auxiliar, int linha_auxiliar){
	int Indice_Lista; // Usada para percorrer a lista de pessoas
	int Indice_Pessoa; // Usada para organizar as pessoas na lista
	if(Verificar_Teatro_Vazio(TEATRO)){
		printf("O TEATRO ESTA VAZIO!\n");
	}else{
		for(Indice_Lista=TEATRO->primeiro; (Indice_Lista!=TEATRO->ultimo) && (pessoa->RG > TEATRO->pessoas[Indice_Lista].RG); Indice_Lista++);
		if((Indice_Lista==TEATRO->ultimo) || (TEATRO->pessoas[Indice_Lista].RG != pessoa->RG)){
		    system("cls");
			printf("PESSOA COM ESTE RG NAO ENCONTRADO!\n");
		}else{
		    if((TEATRO->pessoas[Indice_Lista].coluna_teatro != coluna_auxiliar) || (TEATRO->pessoas[Indice_Lista].linha_teatro != linha_auxiliar)){
		        system("cls");
                printf("PESSOA ENCONTRADA MAS ESTA SENTADA EM LOCAL\n");
                printf("DIFERENTE DO LOCAL INDICADO 'EXCLUSAO ABORTADA'.\n");
		    }else{
                *pessoa=TEATRO->pessoas[Indice_Lista];
                for(Indice_Pessoa=Indice_Lista; Indice_Pessoa<TEATRO->ultimo; Indice_Pessoa++){
                    TEATRO->pessoas[Indice_Pessoa]=TEATRO->pessoas[Indice_Pessoa+1];
                }
                TEATRO->ultimo--;
                TEATRO->MAT[linha_auxiliar][coluna_auxiliar] = 0;
                system("cls");
                printf("PESSOA EXCLUIDA DA LISTA COM SUCESSO!\n");
		    }
		}
	}
}

void Exibir_Lista(Lista_Sequencial_Estatica *TEATRO){
	int contador_posicoes;//Posicoes do VETOR
	system("cls");
	if(TEATRO->primeiro == TEATRO->ultimo){
		printf("O TEATRO ESTA VAZIO!\n");
	}
	printf("----------- LISTAGEM -----------\n");
	for(contador_posicoes = TEATRO->primeiro; contador_posicoes < TEATRO->ultimo; contador_posicoes++){
	    printf("Coluna onde esta sentdado:\t\t%d\n", TEATRO->pessoas[contador_posicoes].coluna_teatro - COLUNA/2);
	    printf("Linha onde esta sentdado:\t\t%d\n", TEATRO->pessoas[contador_posicoes].linha_teatro + 1);
		printf("RG:\t\t%d\n", TEATRO->pessoas[contador_posicoes].RG);
		printf("Nome:\t\t%s\n", TEATRO->pessoas[contador_posicoes].nome);
		printf("Tel. Res:\t%s\n", TEATRO->pessoas[contador_posicoes].telRes);
		printf("\n");
	}
	printf("----------- LISTAGEM -----------\n");
}

int main(){

	Lista_Sequencial_Estatica TEATRO;
	Tipo_Pessoa pessoa;

	int opcao;
    int linha_auxiliar = 0;//linha onde senta a pessoa a ser removida
    int coluna_auxiliar = 0;//coluna onde senta a pessoa a ser removida

	Criar_Teatro_Vazio(&TEATRO);

	do{
		printf("\nSelecione uma opcao:\n");
		printf("\t1 - Comprar/Reservar uma poltrona\n");
		printf("\t2 - Vender/Liberar uma poltrona\n");
		printf("\t3 - Mostrar lista de espectadores de um espetaculo \n");
		printf("\t4 - Mostrar o Teatro\n");
		printf("\t0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				break;
			case 1:
				Ler_Pessoa(&TEATRO,&pessoa);
				Inserir_Pessoa_Lista(&TEATRO, pessoa);
				break;
			 case 2://Aqui pega a poltrona que deseja desocupar
                do{
                    system("cls");
                    printf("Informe a coluna e a linha onde deseja vender\n ");
                    printf("da seguinte forma (2 3)\n");
                    scanf("%d %d",&linha_auxiliar,&coluna_auxiliar);
                    fflush(stdin);
                }while ((coluna_auxiliar < -(COLUNA/2))||(coluna_auxiliar == 0)||((coluna_auxiliar > COLUNA/2)||(linha_auxiliar < 1)||(linha_auxiliar > LINHA + 2)));
                linha_auxiliar = linha_auxiliar - 1;
                coluna_auxiliar = coluna_auxiliar + COLUNA/2 ;
                if(TEATRO.MAT[linha_auxiliar][coluna_auxiliar] == 0){
                    printf("Este local ja esta desocupado.\n");
                    break;
                }
                do{
                    printf("INFORME SEU RG : ");
                    scanf("%d", &pessoa.RG);
                }while(pessoa.RG < 0);
				Remover_Pessoa_Lista(&TEATRO, &pessoa,coluna_auxiliar, linha_auxiliar);
				break;
			case 3:
				Exibir_Lista(&TEATRO);
				break;
            case 4:
                Exibir_Teatro(&TEATRO);
                break;
			default:
				printf("OPCAO INVALIDA!\n");
		}
	}while(opcao!=0);
    system("pause");
	return 0;
}
