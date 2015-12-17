#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct onibus{
    char destinofinal[20];
    int cod_destinofinal;
    char origem[20];
    int cod_origem;
    char motorista[20];
    int cod_motorista;
    struct passageiro{
        char nomepassageiro[20];
        int identidade;
        int tel;
       // int assento;
        char endereco[30];
        char parente[20];
    }vetorpassageiro[48];
}vetoronibus[2];//São duas posições porque é ida e volta
void zerar_vetor(){
    int cont;
    for(cont=1;cont<49;cont++){
        strcpy(vetoronibus[0].vetorpassageiro[cont].nomepassageiro,"\0");
        vetoronibus[0].vetorpassageiro[cont].identidade=0;
        vetoronibus[0].vetorpassageiro[cont].tel=0;
        strcpy(vetoronibus[0].vetorpassageiro[cont].endereco,"\0");
        strcpy(vetoronibus[0].vetorpassageiro[cont].parente,"\0");
    }
}

void comprar_passagem(){
    int assento=0;
    int opcao=0;
    int a=0;
    do{
        printf("Digite o numero do assento desejado.\n");
        scanf("%d",&assento);
        if(vetoronibus[0].vetorpassageiro[assento].identidade!=0){
            printf("Esta poltrona esta ocupada escolha outra.\n");
        }
        if((assento<1)||(assento>48)){
            printf("Este assento não existe.\n");
        }
    }while((assento<1)||(assento>48)||(vetoronibus[0].vetorpassageiro[assento].identidade!=0));
    do{
        printf("Voce ja possui cadastro junto a nossa empresa ?\n");
        printf("Se sim digite 1 se não digite 2.\n");
        scanf("%d",&opcao);
    }while((opcao!=1)&&(opcao!=2));
    switch(opcao)
    {
        case 1:
            printf("Digite o sua identidade.\n");/////////////
        break;
        case 2:
            printf("Digite o seu nome 'no maximo 20 caracteres'.\n");
            getchar();
            gets(vetoronibus[0].vetorpassageiro[assento].nomepassageiro);
            printf("Digite sua identidade.\n");
            getchar();
            scanf("%d%*c",&vetoronibus[0].vetorpassageiro[assento].identidade);
            printf("Digite um telefone de contato.\n");
            getchar();
            scanf("%d%*c",&vetoronibus[0].vetorpassageiro[assento].tel);
            printf("Digite o nome de uma pessoa a ser informada em caso de acidente 'no maximo 20 caracteres'.\n");
            getchar();
            gets(vetoronibus[0].vetorpassageiro[assento].parente);
            printf("Digite seu endereco'no maximo 30 caracteres.'\n");
            getchar();
            gets(vetoronibus[0].vetorpassageiro[assento].endereco);
            printf("Sua passagem foi comprada com sucesso.\n");
            do{
                printf("Digite 1 para voltar ao menu ou digite 2 para fechar programa.\n");
                scanf("%d",&a);
            }while((a!=1)&&(a!=2));
            if(a==1){
                system("cls");
                main();
            }
            if(a==2){
                exit(0);
            }
        break;
        default:
            printf("Opção invalida");
    }
}
void auterar_venda_assento(){
    int opcao=0;
    int identidad=0;
    int cont=0;
    int marcador=0;
    int a;
    do{
        printf("Deseja mudar para qual poltrona ?\n");
        scanf("%d",&opcao);
        if(vetoronibus[0].vetorpassageiro[opcao].identidade!=0){
            printf("Esta poltrona esta ocupada escolha outra.\n");
        }
        if((opcao<1)||(opcao>48)){
            printf("Este assento não existe.\n");
        }
    }while((opcao<1)||(opcao>48)||(vetoronibus[0].vetorpassageiro[opcao].identidade!=0));
    printf("Esta poltrona esta vazia, voce sera colocado nela.\n");
    printf("Qual a sua identidade ?\n");
    scanf("%d",&identidad);
    while(cont<48){
        if(vetoronibus[0].vetorpassageiro[cont].identidade==identidad){
            strcpy(vetoronibus[0].vetorpassageiro[opcao].nomepassageiro,vetoronibus[0].vetorpassageiro[cont].nomepassageiro);
            vetoronibus[0].vetorpassageiro[opcao].identidade=vetoronibus[0].vetorpassageiro[cont].identidade;
            vetoronibus[0].vetorpassageiro[opcao].tel=vetoronibus[0].vetorpassageiro[cont].tel;
            strcpy(vetoronibus[0].vetorpassageiro[opcao].endereco,vetoronibus[0].vetorpassageiro[cont].endereco);
            strcpy(vetoronibus[0].vetorpassageiro[opcao].parente,vetoronibus[0].vetorpassageiro[cont].parente);
            strcpy(vetoronibus[0].vetorpassageiro[cont].nomepassageiro,"\0");
            vetoronibus[0].vetorpassageiro[cont].identidade=0;
            vetoronibus[0].vetorpassageiro[cont].tel=0;
            strcpy(vetoronibus[0].vetorpassageiro[cont].endereco,"\0");
            strcpy(vetoronibus[0].vetorpassageiro[cont].parente,"\0");
            marcador=1;
                printf("Digite 1 para voltar ao menu ou digite 2 para fechar programa.\n");
                scanf("%d",&a);
            if(a==1){
                system("cls");
                main();
            }
            if(a==2){
                exit(0);
            }
        }
        else{
            cont++;
        }
    }
}
void remover_venda(){
    int identidade;
    int marcador;
    int cont=0;
    printf("Digite sua identidade.\n");
    scanf("%d",&identidade);
    for(cont=0;cont<48;cont++){
        if(vetoronibus[0].vetorpassageiro[cont].identidade==identidade){
            strcpy(vetoronibus[0].vetorpassageiro[cont].nomepassageiro,"\0");
            vetoronibus[0].vetorpassageiro[cont].identidade=0;
            vetoronibus[0].vetorpassageiro[cont].tel=0;
            strcpy(vetoronibus[0].vetorpassageiro[cont].endereco,"\0");
            strcpy(vetoronibus[0].vetorpassageiro[cont].parente,"\0");
            printf("Seu dinheiro sera estornado a sua conta em 3 dias uteis");
        }
    }

}
void imprimir_lista(){
    int cont=0;
    int marcador=0;
    for(cont=0;cont<48;cont++){
        if(vetoronibus[0].vetorpassageiro[cont].identidade!=0){
            printf("Passageiro: %s Assento numero: %d \n",vetoronibus[0].vetorpassageiro[cont].nomepassageiro,(cont+1));
            printf("identidade numero: %d.\n",vetoronibus[0].vetorpassageiro[cont].identidade);
            printf("Telefone numero: %d.\n",vetoronibus[0].vetorpassageiro[cont].tel);
            printf("Endereco: %s.\n",vetoronibus[0].vetorpassageiro[cont].endereco);
            printf("Parente a ser informado: %s.\n",vetoronibus[0].vetorpassageiro[cont].parente);
            marcador=1;
        }
    }
    if(marcador==0){
        printf("O onibus ainda esta vazio.\n");
    }
}
void exibir_layout(){
    int cont=1;
    int a=1;
    while(cont<41){
        printf("%i %i   %i %i\n%i %i   %i %i\n",(cont),(cont+1),(cont+5),(cont+4),(cont+2),(cont+3),(cont+7),(cont+6));
        cont+=8;
    }
    cont=41;
    printf("%i %i   %i %i\n%i %i   wc wc\n%i %i   wc wc\n\n",(cont),(cont+1),(cont+5),(cont+4),(cont+2),(cont+3),(cont+6),(cont+7));
    for(cont=0;cont<48;cont++){
        if(vetoronibus[0].vetorpassageiro[cont].identidade!=0){
            printf("Assento: %i Ocupado   ",(cont+1));
            a++;
        }
        else{
            printf("Assento: %i Livre   ",(cont+1));
            a++;
        }
        if(a%3==0){
            printf("\n");
        }
    }
}
void dados_administrativos(){
    printf("Informe o destino final.\n");
    gets(vetoronibus[0].destinofinal);
    printf("Informe o codigo do destino final.\n");
    scanf("%i",&vetoronibus[0].cod_destinofinal);
    printf("Informe a origem.\n");
    gets(vetoronibus[0].origem);
    printf("Informe o codigo de origem.\n");
    scanf("%i",&vetoronibus[0].cod_origem);
    printf("Informe o nome do motorista.\n");
    gets(vetoronibus[0].motorista);
    printf("Informe o codigo do motorista.\n");
    scanf("%i",&vetoronibus[0].cod_motorista);
}
void exibir_dados_administrativos(){
    printf("Destino final: %s, codigo: %i.\n",vetoronibus[0].destinofinal,vetoronibus[0].cod_destinofinal);
    printf("Origem: %s, codigo: %i.\n",vetoronibus[0].origem,vetoronibus[0].cod_origem);
    printf("Nome do motorista: %s, codigo: %i.\n",vetoronibus[0].motorista,vetoronibus[0].cod_motorista);
}

int main(){
    int opcao=0;
    do{
        printf("Digite 1 para comprar uma passagem.\n");
        printf("Digite 2 para auterar uma venda/assento.\n");
        printf("Digite 3 para remover uma venda.\n");
        printf("Digite 4 para exibir o layout do onibus.\n");
        printf("Digite 5 para imprimir lista de passageiros.\n");
        printf("Digite 6 para inserir dados administrativos.\n");
        printf("Digite 7 para exibir dados administrativos.\n");
        printf("Digite 8 para 'SAIR' do programa.\n");
        scanf("%d",&opcao);
        system("cls");
    }while((opcao<1)||(opcao>6));
    switch(opcao)
    {
        case 1:
            comprar_passagem();
        break;
        case 2:
            auterar_venda_assento();
        break;
        case 3:
            remover_venda();
        break;
        case 4:
            exibir_layout();
        break;
        case 5:
            imprimir_lista();
        break;
        case 6:
            dados_administrativos();
        break;
        case 7:
            exibir_dados_administrativos();
        break;
        case 8:
            return 0;
        break;
        default:
            printf("Opcao invalida");
        break;
    }
}
