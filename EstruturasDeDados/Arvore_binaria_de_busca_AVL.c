#include <stdio.h>
#include <stdlib.h>
/*
===================================
    ARVORE BINARIA DE BUSCA AVL
===================================
*/

struct ArvoreAVL{
    int Codigo;
    int Fator_Balanceamento;
    struct ArvoreAVL *PAI;
    struct ArvoreAVL *ESQUERDA;
    struct ArvoreAVL *DIREITA;
};

int Arvore_Altura(struct ArvoreAVL *arvore){

    //Criacao das variaveis auxiliares
    int ESQUERDA, DIREITA;

    //Inicio do Calculo da Altura
    if(arvore == NULL){
        return -1;
    }
    ESQUERDA = Arvore_Altura(arvore->ESQUERDA);
    DIREITA = Arvore_Altura(arvore->DIREITA);
    //Fim do Calculo da Altura

    if(ESQUERDA > DIREITA){
        return ESQUERDA + 1;
    }else{
        return DIREITA + 1;
    }
}

struct  ArvoreAVL *Rotacao_ESQUERDA_ESQUERDA(struct ArvoreAVL *arvore){

    //Criacao das variaveis auxiliares
    struct  ArvoreAVL *arvore_AUXILIAR;
    arvore_AUXILIAR = arvore->ESQUERDA;

    //Inicio da Rotacao
    arvore->ESQUERDA = arvore_AUXILIAR->DIREITA;
    if(arvore_AUXILIAR->DIREITA != NULL){
        arvore_AUXILIAR->DIREITA->PAI = arvore;
    }
    arvore_AUXILIAR->DIREITA = arvore;
    arvore_AUXILIAR->PAI = arvore->PAI;
    if(arvore->PAI != NULL){
        if(arvore->PAI->ESQUERDA == arvore){
            arvore->PAI->ESQUERDA = arvore_AUXILIAR;
        }else{
            arvore->PAI->DIREITA = arvore_AUXILIAR;
        }
    }
    arvore->PAI = arvore_AUXILIAR;
    //Fim da Rotacao

    //Calcula novamente o Fator de Balanceamento
    arvore_AUXILIAR->Fator_Balanceamento = Arvore_Altura(arvore_AUXILIAR->ESQUERDA) - Arvore_Altura(arvore_AUXILIAR->DIREITA);
    arvore->Fator_Balanceamento = Arvore_Altura(arvore->ESQUERDA) - Arvore_Altura(arvore->DIREITA);

    return arvore_AUXILIAR;
}

struct ArvoreAVL *Rotacao_DIREITA_DIREITA (struct ArvoreAVL *arvore){

    //Criacao das variaveis auxiliares
    struct ArvoreAVL *arvore_AUXILIAR;
    arvore_AUXILIAR = arvore->DIREITA;

    //Inicio da Rotacao
    arvore->DIREITA = arvore_AUXILIAR->ESQUERDA;
    if(arvore_AUXILIAR->ESQUERDA != NULL){
        arvore_AUXILIAR->ESQUERDA->PAI = arvore;
    }
    arvore_AUXILIAR->ESQUERDA = arvore;
    arvore_AUXILIAR->PAI = arvore->PAI;
    if(arvore->PAI != NULL){
        if(arvore->PAI->ESQUERDA == arvore){
            arvore->PAI->ESQUERDA = arvore_AUXILIAR;
        }else{
            arvore->PAI->DIREITA = arvore_AUXILIAR;
        }
    }
    arvore->PAI = arvore_AUXILIAR;
    //Fim da Rotacao

    //Calcula novamente o Fator de Balanceamento
    arvore_AUXILIAR->Fator_Balanceamento = Arvore_Altura(arvore_AUXILIAR->ESQUERDA) - Arvore_Altura(arvore_AUXILIAR->DIREITA);
    arvore->Fator_Balanceamento = Arvore_Altura(arvore->ESQUERDA) - Arvore_Altura(arvore->DIREITA);

    return arvore_AUXILIAR;
}

void Remover_Elemento(struct ArvoreAVL **arvore, int Codigo){

    //Criacao das variaveis auxiliares
    int Codigo_Auxiliar;
    struct ArvoreAVL * arvore_AUXILIAR;

    //Inicio dos Casos de Remoção
    if(*arvore == NULL){
        //Se o Elemento não for encontrado
        printf("Este Elemento Não Existe ou já foi Removido Anteriormente\n");
        return;
    }
    if(Codigo < (*arvore)->Codigo){

        Remover_Elemento(&((*arvore)->ESQUERDA),Codigo);
        (*arvore)->Fator_Balanceamento = Arvore_Altura((*arvore)->ESQUERDA) - Arvore_Altura((*arvore)->DIREITA);
        if((*arvore)->Fator_Balanceamento == -2){

            if((*arvore)->DIREITA->Fator_Balanceamento != 1){
                (*arvore) = Rotacao_DIREITA_DIREITA((*arvore));
            }else if((*arvore)->DIREITA->Fator_Balanceamento == 1){
                (*arvore)->DIREITA = Rotacao_ESQUERDA_ESQUERDA((*arvore)->DIREITA);
                (*arvore) = Rotacao_DIREITA_DIREITA((*arvore));
            }
        }
    }else{
        if(Codigo > (*arvore)->Codigo){

            Remover_Elemento(&((*arvore)->DIREITA), Codigo);
            (*arvore)->Fator_Balanceamento = Arvore_Altura((*arvore)->ESQUERDA) - Arvore_Altura((*arvore)->DIREITA);
            if((*arvore)->Fator_Balanceamento == 2){
                if((*arvore)->ESQUERDA->Fator_Balanceamento != -1){
                    (*arvore) = Rotacao_ESQUERDA_ESQUERDA ((*arvore));
                }else if((*arvore)->ESQUERDA->Fator_Balanceamento == -1){
                    (*arvore)->ESQUERDA = Rotacao_DIREITA_DIREITA((*arvore)->ESQUERDA);
                    (*arvore) = Rotacao_ESQUERDA_ESQUERDA((*arvore));
                }
            }
        }else{
            //Se encontrar o codigo correspondente irá remover
            if(Codigo == (*arvore)->Codigo){
                if (((*arvore)->ESQUERDA == NULL) && ((*arvore)->DIREITA==NULL)){
                    free(*arvore);
                    *arvore = NULL;
                }else{

                    if((((*arvore)->ESQUERDA == NULL) && ((*arvore)->DIREITA!=NULL)) || ((*arvore)->Fator_Balanceamento == -1)){

                        arvore_AUXILIAR = (*arvore)->DIREITA;
                        while(arvore_AUXILIAR->ESQUERDA != NULL){
                            arvore_AUXILIAR = arvore_AUXILIAR->ESQUERDA;
                        }
                        Codigo_Auxiliar = arvore_AUXILIAR->Codigo;
                        Remover_Elemento(&((*arvore)), arvore_AUXILIAR->Codigo);
                        (*arvore)->Codigo = Codigo_Auxiliar;
                    }else{

                        arvore_AUXILIAR = (*arvore)->ESQUERDA;
                        while(arvore_AUXILIAR->DIREITA != NULL)
                            arvore_AUXILIAR = arvore_AUXILIAR->DIREITA;

                        Codigo_Auxiliar = arvore_AUXILIAR->Codigo;
                        Remover_Elemento(&((*arvore)), arvore_AUXILIAR->Codigo);
                        (*arvore)->Codigo = Codigo_Auxiliar;

                    }
                }
            }
        }
    }
}

void Inserir_Elemento_Arvore(struct ArvoreAVL **arvore,struct ArvoreAVL **PAI, int numero){

    if(*arvore == NULL){

        *arvore = (struct ArvoreAVL *)malloc(sizeof(struct ArvoreAVL));
        (*arvore)->ESQUERDA = NULL;
        (*arvore)->DIREITA = NULL;
        (*arvore)->Codigo = numero;
        (*arvore)->PAI = (*PAI);
        (*arvore)->Fator_Balanceamento = 0;
    }else{

        if(numero < (*arvore)->Codigo){

            Inserir_Elemento_Arvore(&(*arvore)->ESQUERDA,&(*arvore), numero);
            (*arvore)->Fator_Balanceamento = Arvore_Altura((*arvore)->ESQUERDA ) - Arvore_Altura((*arvore)->DIREITA);
            if((*arvore)->Fator_Balanceamento == 2){

                if((*arvore)->ESQUERDA->Fator_Balanceamento == 1){
                    (*arvore) = Rotacao_ESQUERDA_ESQUERDA((*arvore));
                }
                else if((*arvore)->ESQUERDA->Fator_Balanceamento == -1){
                    (*arvore)->ESQUERDA = Rotacao_DIREITA_DIREITA((*arvore)->ESQUERDA);
                    (*arvore) = Rotacao_ESQUERDA_ESQUERDA((*arvore));
                }
            }
        }else{
            if(numero > (*arvore)->Codigo){

                Inserir_Elemento_Arvore(&(*arvore)->DIREITA,&(*arvore), numero);
                (*arvore)->Fator_Balanceamento = Arvore_Altura((*arvore)->ESQUERDA) - Arvore_Altura((*arvore)->DIREITA);
                if((*arvore)->Fator_Balanceamento == -2){

                    if((*arvore)->DIREITA->Fator_Balanceamento == -1){
                        (*arvore) = Rotacao_DIREITA_DIREITA((*arvore));
                    }else if((*arvore)->DIREITA->Fator_Balanceamento == 1){
                        (*arvore)->DIREITA = Rotacao_ESQUERDA_ESQUERDA((*arvore)->DIREITA);
                        (*arvore) = Rotacao_DIREITA_DIREITA((*arvore));
                    }
                }
            }
        }
    }
}

void Exibir_PreOrdem(struct ArvoreAVL *arvore){

    if(arvore){
        printf("Codigo: %d \nFator de Balanceamento: (%d)\n\n", arvore->Codigo, arvore->Fator_Balanceamento);
        Exibir_PreOrdem(arvore->ESQUERDA);
        Exibir_PreOrdem(arvore->DIREITA);
    }
}

void Exibir_InOrdem(struct ArvoreAVL *arvore){

    if(arvore){
        Exibir_InOrdem(arvore->ESQUERDA);
        printf("Codigo: %d \nFator de Balanceamento: (%d)\n\n", arvore->Codigo, arvore->Fator_Balanceamento);
        Exibir_InOrdem(arvore->DIREITA);
    }
}

void Exibir_PosOrdem(struct ArvoreAVL *arvore){

    if(arvore){
        Exibir_PosOrdem(arvore->ESQUERDA);
        Exibir_PosOrdem(arvore->DIREITA);
        printf("Codigo: %d\n\n", arvore->Codigo);
    }
}

void Exibir_PreOrdem2(struct ArvoreAVL *arvore){

    if(arvore){
        printf("Codigo: %d\n\n", arvore->Codigo);
        Exibir_PreOrdem2(arvore->ESQUERDA);
        Exibir_PreOrdem2(arvore->DIREITA);
    }
}

void Exibir_InOrdem2(struct ArvoreAVL *arvore){

    if(arvore){
        Exibir_InOrdem2(arvore->ESQUERDA);
        printf("Codigo: %d\n\n", arvore->Codigo);
        Exibir_InOrdem2(arvore->DIREITA);
    }
}

void Exibir_PosOrdem2(struct ArvoreAVL *arvore){

    if(arvore){
        Exibir_PosOrdem2(arvore->ESQUERDA);
        Exibir_PosOrdem2(arvore->DIREITA);
        printf("Codigo: %d\n\n", arvore->Codigo);
    }
}

void Destruir_Arvore(struct ArvoreAVL **arvore){

    if ((*arvore) != NULL){
        Destruir_Arvore(&(*arvore)->dir);
        Destruir_Arvore(&(*arvore)->esq);
        free((*arvore));
        (*arvore) = NULL;
    }
}

int main(){

    //Criacao das variaveis
    int opcao;
    int numero;
    struct ArvoreAVL *arvore, *PAI;
    arvore = NULL;
    PAI = NULL;

    //Menu
    do {
        printf("Selecione uma opcaocao:\n");
        printf("\t1 - Inserir Elemento na Arvore AVL\n");
        printf("\t2 - Remover Pessoa da arvore\n");
        printf("\t3 - Destruir Arvore\n");
        printf("\t4 - Mostrar Arvore com Fator de Balanceamento Pre-Ordem\n");
        printf("\t5 - Mostrar Arvore sem Fator de Balanceamento Pre-Ordem\n");
        printf("\t6 - Mostrar Arvore com Fator de Balanceamento In-Ordem\n");
        printf("\t7 - Mostrar Arvore sem Fator de Balanceamento In-Ordem\n");
        printf("\t8 - Mostrar Arvore com Fator de Balanceamento Pos-Ordem\n");
        printf("\t9 - Mostrar Arvore sem Fator de Balanceamento Pos-Ordem\n");
        printf("\t0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 0:
                break;
            case 1:
                printf("Digite o numero a Inserir Elemento na arvore: ");
                scanf("%d", &numero);
                Inserir_Elemento_Arvore(&arvore, &PAI, numero);
                break;
            case 2:
                printf("Digite o Codigo a ser Removido: ");
                scanf("%d", &numero);
                Remover_Elemento(&arvore, numero);
                break;
            case 3:
                Destruir_Arvore(&arvore);
                printf("Todos os Elementos foram Removidos!\n");
                break;
            case 4:
                Exibir_PreOrdem(arvore);
                break;
            case 5:
                Exibir_PreOrdem2(arvore);
                break;
            case 6:
                Exibir_InOrdem(arvore);
                break;
            case 7:
                Exibir_InOrdem2(arvore);
                break;
            case 8:
                Exibir_PosOrdem(arvore);
                break;
            case 9:
                Exibir_PosOrdem2(arvore);
                break;
            default:
                printf("OPCAO INVALIDA!\n");
        }

    }while(opcao != 0);
    system("pause");
    return 0;
}

