//ALUNO:RICARDO HENRIQUE INÁCIO MATRICULA:122285 TURMA:A
//ALUNO:BRUNO MARTINS MATRICULA:122250 TURMA:A
//ALUNO:KAIO CRISTIAN COSTA SILVA MATRICULA:122266 TURMA:A
#include<stdio.h>
#include<stdlib.h>
#define MAXL 100
typedef int matriz[MAXL][MAXL];
/*
    =================================
    1 indica que a celula esta viva
    0 indica que a celula esta morta
    =================================
*/

void criacao_anulacao_do_universo(){
    /*======================CRIACAO E ANULACAO DA MATRIZ========================*/
    int i,j;//contador_visinhasadores para o for
    int ordem_da_matriz;
   //Usuario digita o tamanho da matriz
    int geracoes;//geracoes criadas do jogo da vida
    do{
            system("cls");
            printf("========================================\n");
            printf("Este e o GAME OF LIFE digite um valor entre\n");
            printf("0 e 101 para ser a tamanho de seu universo.\n");
            printf("========================================\n");
            scanf("%i",&ordem_da_matriz);
            system("cls");
        }while((ordem_da_matriz<1)||(ordem_da_matriz>100));
    matriz universo;//criacao do universo
    //Usuario digita o tamanho da matriz
    //Inicializando a matriz com 0 (vaziao/desabitado)
        for(i=0;i<MAXL;i++){
           for(j=0;j<MAXL;j++){
                universo[i][j]=0;
           }
        }
    //Inicializando a matriz com 0 (vazio/desabitado)
    /*======================CRIACAO E ANULACAO DA MATRIZ========================*/

    menu(universo,ordem_da_matriz);
}

void imprimir_matriz_estatica(matriz universo,int ordem_da_matriz){

     /*=================IMPRIMIR MATRIZ DESABITADA=======================*/
     int i,j;
         //Imprimir guias superior para a matriz
        printf("   ");//para manter um alinhamento
        for(j=1;j<ordem_da_matriz+1;j++){
            if(j<10){
                printf("0");
            }//para manter um alinhamento
            printf("%i ",j);
        }
        printf("\n\n");
        //Imprimir guias superior para a matriz

        for(i=0;i<ordem_da_matriz;i++){
            //Imprimir guias inferior para a matriz
                if(i<9){//porque la em baixo eu somarei 1 ao i
                    printf("0");
                }//para manter um alinhamento
                printf("%i ",(i+1));
            //Imprimir guias inferior para a matriz
            for(j=0;j<ordem_da_matriz;j++){
                if(universo[i][j]==0){
                    printf("   ");
                }
                else{
                    printf(" * ");
                }
           }
           printf("\n");
        }
        //Imprimir matriz
        printf("\n\n ");
    /*=================IMPRIMIR MATRIZ DESABITADA==================*/
}

void menu_secundario(matriz universo,int ordem_da_matriz){
    int opcao;
    do{
        system("cls");
        printf("Digite 1 para preencher seu universo com a forma 'BLOCK'.\n");
        printf("Digite 2 para preencher seu universo com a forma 'BEEHIVE'.\n");
        printf("Digite 3 para preencher seu universo com a forma 'LOAF'.\n");
        printf("Digite 4 para preencher seu universo com a forma 'BOAT'.\n");
        printf("Digite 5 para preencher seu universo com a forma 'BLINKER'.\n");
        printf("Digite 6 para preencher seu universo com a forma 'TOAD'.\n");
        printf("Digite 7 para preencher seu universo com a forma 'BEACON'.\n");
        printf("Digite 8 para preencher seu universo com a forma 'PULSAR'.\n");
        printf("Digite 9 para preencher seu universo com a forma 'GLIDER'.\n");
        printf("Digite 10 para preencher seu universo com a forma 'LIGHTWEIGHT SPACESHIP'.\n");
        printf("Digite 11 para preencher seu universo com a forma 'R-PENTONIME'.\n");
        printf("Digite 12 para preencher seu universo com a forma 'DIEHARD'.\n");
        printf("Digite 13 para preencher seu universo com a forma 'ACORN'.\n");
        printf("Digite 14 para preencher seu universo com a forma 'GOSPER GLIDER GUN'.\n");
        printf("Digite 15 para VOLTAR ao menu anterior.\n");
        scanf("%i",&opcao);
    }while((opcao<0)||(opcao>16));
    switch(opcao){
        case 1:
            povoamento_block(universo,ordem_da_matriz);
        break;
        case 2:
            povoamento_beehive(universo,ordem_da_matriz);
        break;
        case 3:
            povoamento_loaf(universo,ordem_da_matriz);
        break;
        case 4:
            povoamento_boat(universo,ordem_da_matriz);
        break;
        case 5:
            povoamento_blinker(universo,ordem_da_matriz);
        break;
        case 6:
            povoamento_toad(universo,ordem_da_matriz);
        break;
        case 7:
            povoamento_beacon(universo,ordem_da_matriz);
        break;
        case 8:
            povoamento_pulsar(universo,ordem_da_matriz);
        break;
        case 9:
            povoamento_glider(universo,ordem_da_matriz);
        break;
        case 10:
            povoamento_lightweight_spaceship(universo,ordem_da_matriz);
        break;
        case 11:
            povoamento_r_pentomino(universo,ordem_da_matriz);
        break;
        case 12:
            povoamento_diehard(universo,ordem_da_matriz);
        break;
        case 13:
            povoamento_acorn(universo,ordem_da_matriz);
        break;
        case 14:
            gosper_glider_gun(universo,ordem_da_matriz);
        break;
        case 15:
            menu(universo,ordem_da_matriz);
        break;
        default:
            printf("Opcao invalida");
        break;
    }
}

int menu(matriz universo,int ordem_da_matriz){

     int opcao;//opcoes a escolha do usuario
     /*=====================MENU========MENU====================================*/
        do{
            system("cls");
            imprimir_matriz_estatica(universo,ordem_da_matriz);
            printf("\nDigite 1 para preencher seu universo manualmente.\n");
            printf("Digite 2 para preencher de forma aleatoria.\n");
            printf("Digite 3 para preencher com formas classicas.\n");
            printf("Digite 4 para ver seu universo se desenvolver.\n");
            printf("Digite 5 para SAIR do programa.\n\n");
            scanf("%i",&opcao);
        }while((opcao<0)||(opcao>5));

        switch(opcao){
            case 1:
                povoamento_manual_universo(universo,ordem_da_matriz);
            break;
            case 2:
                povoamento_aleatorio_universo(universo,ordem_da_matriz);
            break;

            case 3:
                menu_secundario(universo,ordem_da_matriz);
            break;
            case 4:
               matriz_geracoes(universo,ordem_da_matriz);
            break;
            case 5:
                exit(1);
            break;
            default:
                printf("Opcao invalida");
            break;
        }
    /*=====================MENU========MENU====================================*/
}

void povoamento_manual_universo(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO MANUAL================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(universo[linha][coluna]==1){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO MANUAL================================*/
}

void povoamento_aleatorio_universo(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO ALEATORIO================================*/
    int i,j;//contador_visinhasadores para as posicoes do universo
    int percentual;//percentual de universo vivas
    int quantidade_a_ser_preenchida;//quantidade de universo vivas
    int quantidade_total_matriz;//total de universo vagas da matriz ordem_da_matriz^2
    do{
        system("cls");
        printf("\nDigite um percentual de universo vivas.\n");
        scanf("%i",&percentual);
    }while((percentual<2)||percentual>99);
    quantidade_total_matriz=ordem_da_matriz*ordem_da_matriz;
    quantidade_a_ser_preenchida=quantidade_total_matriz*percentual/100;

    /*=============GERANDO POSICOES ALEATORIAS==================================*/
    srand(time(NULL));
    while(quantidade_a_ser_preenchida>0){
        i=rand()%(ordem_da_matriz);
        j=rand()%(ordem_da_matriz);
        if(universo[i][j]==0){//verifica se a posicao esta vazia
            universo[i][j]=1;
            quantidade_a_ser_preenchida--;
        }
    }
    imprimir_matriz_estatica(universo,ordem_da_matriz);
    menu(universo,ordem_da_matriz);
    /*=============GERANDO POSICOES ALEATORIAS==================================*/
    /*=======================POVOAMENTO ALEATORIO================================*/
}

void povoamento_block(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO BLOCK================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao

    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do BLOCK\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+1>ordem_da_matriz)||(coluna+1>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna]=1;
            universo[linha][coluna+1]=1;
            universo[linha+1][coluna]=1;
            universo[linha+1][coluna+1]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO BLOCK================================*/

}

void povoamento_beehive(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO BEEHIVE================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do BEEHIVE\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+2>ordem_da_matriz)||(coluna+3>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna+1]=1;
            universo[linha][coluna+2]=1;
            universo[linha+1][coluna]=1;
            universo[linha+1][coluna+3]=1;
            universo[linha+2][coluna+1]=1;
            universo[linha+2][coluna+2]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO BEEHIVE================================*/

}

void povoamento_loaf(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO LOAF================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do LOAF\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+3>ordem_da_matriz)||(coluna+3>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna+1]=1;
            universo[linha][coluna+2]=1;
            universo[linha+1][coluna]=1;
            universo[linha+1][coluna+3]=1;
            universo[linha+2][coluna+1]=1;
            universo[linha+2][coluna+3]=1;
            universo[linha+3][coluna+2]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO LOAF================================*/
}

void povoamento_boat(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO BOAT================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do BOAT\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            //linha+1 e coluna+1 pq ambas as guias se iniciam do 0.
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+2>ordem_da_matriz)||(coluna+2>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna]=1;
            universo[linha][coluna+1]=1;
            universo[linha+1][coluna]=1;
            universo[linha+1][coluna+2]=1;
            universo[linha+2][coluna+1]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO BOAT================================*/
}

void povoamento_blinker(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO BLINKER================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        printf("Digite um local que deseja que haja vida.\n");
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do BLINKER\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha>ordem_da_matriz)||(coluna+2>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna]=1;
            universo[linha][coluna+1]=1;
            universo[linha][coluna+2]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO BLINKER================================*/
}

void povoamento_toad(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO TOAD================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do TOAD\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+1>ordem_da_matriz)||(coluna+3>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna+1]=1;
            universo[linha][coluna+2]=1;
            universo[linha][coluna+3]=1;
            universo[linha+1][coluna]=1;
            universo[linha+1][coluna+1]=1;
            universo[linha+1][coluna+2]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO TOAD================================*/
}

void povoamento_beacon(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO BEACON================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do BEACON\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+3>ordem_da_matriz)||(coluna+3>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna]=1;
            universo[linha][coluna+1]=1;
            universo[linha+1][coluna]=1;
            universo[linha+2][coluna+3]=1;
            universo[linha+3][coluna+2]=1;
            universo[linha+3][coluna+3]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO BEACON================================*/
}

void povoamento_pulsar(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO PULSAR================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do PULSAR\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+14>ordem_da_matriz)||(coluna+14>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            /*========1º grupo de L========*/
            universo[linha][coluna+4]=1;
            universo[linha+1][coluna+4]=1;
            universo[linha+2][coluna+4]=1;
            universo[linha+2][coluna+5]=1;
            /*========1º grupo de L========*/

            /*========2º grupo de L========*/
            universo[linha][coluna+10]=1;
            universo[linha+1][coluna+10]=1;
            universo[linha+2][coluna+10]=1;
            universo[linha+2][coluna+9]=1;
            /*========2º grupo de L========*/

            /*========3º grupo de L========*/
            universo[linha+4][coluna+12]=1;
            universo[linha+4][coluna+13]=1;
            universo[linha+4][coluna+14]=1;
            universo[linha+5][coluna+12]=1;
            /*========3º grupo de L========*/

            /*========4º grupo de L========*/
            universo[linha+9][coluna+12]=1;
            universo[linha+10][coluna+12]=1;
            universo[linha+10][coluna+13]=1;
            universo[linha+10][coluna+14]=1;
            /*========4º grupo de L========*/

            /*========5º grupo de L========*/
            universo[linha+12][coluna+9]=1;
            universo[linha+12][coluna+10]=1;
            universo[linha+13][coluna+10]=1;
            universo[linha+14][coluna+10]=1;
            /*========5º grupo de L========*/

            /*========6º grupo de L========*/
            universo[linha+12][coluna+4]=1;
            universo[linha+12][coluna+5]=1;
            universo[linha+13][coluna+4]=1;
            universo[linha+14][coluna+4]=1;
            /*========6º grupo de L========*/

            /*========7º grupo de L========*/
            universo[linha+9][coluna+2]=1;
            universo[linha+10][coluna]=1;
            universo[linha+10][coluna+1]=1;
            universo[linha+10][coluna+2]=1;
            /*========7º grupo de L========*/

            /*========8º grupo de L========*/
            universo[linha+4][coluna]=1;
            universo[linha+4][coluna+1]=1;
            universo[linha+4][coluna+2]=1;
            universo[linha+5][coluna+2]=1;
            /*========8º grupo de L========*/

            /*========1º grupo de QUADRADO========*/
            universo[linha+4][coluna+5]=1;
            universo[linha+4][coluna+6]=1;
            universo[linha+5][coluna+4]=1;
            universo[linha+5][coluna+6]=1;
            universo[linha+6][coluna+4]=1;
            universo[linha+6][coluna+5]=1;
            /*========1º grupo de QUADRADO========*/

            /*========2º grupo de QUADRADO========*/
            universo[linha+4][coluna+8]=1;
            universo[linha+4][coluna+9]=1;
            universo[linha+5][coluna+8]=1;
            universo[linha+5][coluna+10]=1;
            universo[linha+6][coluna+9]=1;
            universo[linha+6][coluna+10]=1;
            /*========2º grupo de QUADRADO========*/

            /*========3º grupo de QUADRADO========*/
            universo[linha+8][coluna+9]=1;
            universo[linha+8][coluna+10]=1;
            universo[linha+9][coluna+8]=1;
            universo[linha+9][coluna+10]=1;
            universo[linha+10][coluna+8]=1;
            universo[linha+10][coluna+9]=1;
            /*========3º grupo de QUADRADO========*/

            /*========4º grupo de QUADRADO========*/
            universo[linha+8][coluna+4]=1;
            universo[linha+8][coluna+5]=1;
            universo[linha+9][coluna+4]=1;
            universo[linha+9][coluna+6]=1;
            universo[linha+10][coluna+5]=1;
            universo[linha+10][coluna+6]=1;
            /*========4º grupo de QUADRADO========*/
        }
        verificador=0;
    }
    /*=======================POVOAMENTO PULSAR================================*/
}

void povoamento_glider(matriz universo, int ordem_da_matriz){

     /*=======================POVOAMENTO GLIDER================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do GLIDER\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+2>ordem_da_matriz)||(coluna+2>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna+1]=1;
            universo[linha+1][coluna+2]=1;
            universo[linha+2][coluna]=1;
            universo[linha+2][coluna+1]=1;
            universo[linha+2][coluna+2]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO GLIDER================================*/
}

void povoamento_lightweight_spaceship(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO LIGHTWEIGHT SPACESHIP================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do LIGHTWEIGHT SPACESHIP\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+3>ordem_da_matriz)||(coluna+4>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna]=1;
            universo[linha][coluna+3]=1;
            universo[linha+1][coluna+4]=1;
            universo[linha+2][coluna+4]=1;
            universo[linha+2][coluna]=1;
            universo[linha+3][coluna+1]=1;
            universo[linha+3][coluna+2]=1;
            universo[linha+3][coluna+3]=1;
            universo[linha+3][coluna+4]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO LIGHTWEIGHT SPACESHIP================================*/
}

void povoamento_r_pentomino(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO R_PENTOMINO================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do R_PENTOMINO\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+2>ordem_da_matriz)||(coluna+2>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna+1]=1;
            universo[linha][coluna+2]=1;
            universo[linha+1][coluna]=1;
            universo[linha+1][coluna+1]=1;
            universo[linha+2][coluna+1]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO R_PENTOMINO================================*/
}

void povoamento_diehard(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO DIEHARD================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do DIEHARD\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+2>ordem_da_matriz)||(coluna+7>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna+6]=1;
            universo[linha+1][coluna]=1;
            universo[linha+1][coluna+1]=1;
            universo[linha+2][coluna+1]=1;
            universo[linha+2][coluna+5]=1;
            universo[linha+2][coluna+6]=1;
            universo[linha+2][coluna+7]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO DIEHARD================================*/
}

void povoamento_acorn(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO ACORN================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do ACORN\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+2>ordem_da_matriz)||(coluna+6>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
            universo[linha][coluna+1]=1;
            universo[linha+1][coluna+3]=1;
            universo[linha+2][coluna]=1;
            universo[linha+2][coluna+1]=1;
            universo[linha+2][coluna+4]=1;
            universo[linha+2][coluna+5]=1;
            universo[linha+2][coluna+6]=1;
        }
        verificador=0;
    }
    /*=======================POVOAMENTO ACORN================================*/
}

void gosper_glider_gun(matriz universo, int ordem_da_matriz){

    /*=======================POVOAMENTO GOSPER GLIDER GUN================================*/
    int linha;//armazenara a linha digitada pelo usuario
    int coluna;//armazenara a coluna digitada pelo usuario
    int verificador=0;//ira ser um flag que quando um receber 1 nao deixara
    //o universo ser povoado na respectiva posicao
    while(1){//Saira do while assim que acionar um FLAG
        system("cls");
        imprimir_matriz_estatica(universo,ordem_da_matriz);
        printf("Voce digitara da seguinte forma 02 05 Indicando a 1 posicao do GOSPER GLIDER GUN\n");
        printf("Onde o 1 digito 02 e a linha\n");
        printf("E o 2 digito 05 e a coluna\n");
        printf("E entre os digitos devera ter um espaco.\n");
        printf("Para sair digite 0 0.\n");
        printf("Digite um local que deseja que haja vida.\n");
        scanf("%i %i",&linha,&coluna);
        linha--;//porque a matriz visivel inicia do 1
        coluna--;//porque a matriz visivel inicia do 1
        if((linha==-1)&&(coluna==-1)){
            menu_secundario(universo,ordem_da_matriz);
        }
        if((linha>=ordem_da_matriz)||(coluna>=ordem_da_matriz)||(linha<0)||(coluna<0)){
            printf("Esta posicao nao existe.\n");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if((linha+8>ordem_da_matriz)||(coluna+35>ordem_da_matriz)){
            printf("Esta forma nao cabe neste local, escolha outro");
            verificador=1;
        }
        /*==VALIDACAO==*/
        if(verificador==0){
	/*========1ª PARTE 'CUBO'==========*/
        universo[linha+4][coluna]=1;
        universo[linha+4][coluna+1]=1;
        universo[linha+5][coluna]=1;
        universo[linha+5][coluna+1]=1;
	/*========1ª PARTE 'CUBO'==========*/

	/*=============2ª PARTE=============*/
        universo[linha+4][coluna+10]=1;
        universo[linha+5][coluna+10]=1;
        universo[linha+6][coluna+10]=1;
        universo[linha+3][coluna+11]=1;
        universo[linha+7][coluna+11]=1;
        universo[linha+2][coluna+12]=1;
        universo[linha+2][coluna+13]=1;
        universo[linha+8][coluna+12]=1;
        universo[linha+8][coluna+13]=1;
        universo[linha+5][coluna+14]=1;
        universo[linha+3][coluna+15]=1;
        universo[linha+7][coluna+15]=1;
        universo[linha+4][coluna+16]=1;
        universo[linha+5][coluna+16]=1;
        universo[linha+6][coluna+16]=1;
        universo[linha+5][coluna+17]=1;
	/*=============2ª PARTE=============*/

	/*=============3ª PARTE=============*/
        universo[linha+2][coluna+20]=1;
        universo[linha+3][coluna+20]=1;
        universo[linha+4][coluna+20]=1;
        universo[linha+2][coluna+21]=1;
        universo[linha+3][coluna+21]=1;
        universo[linha+4][coluna+21]=1;
        universo[linha+1][coluna+22]=1;
        universo[linha+5][coluna+22]=1;
        universo[linha][coluna+24]=1;
        universo[linha+1][coluna+24]=1;
        universo[linha+5][coluna+24]=1;
        universo[linha+6][coluna+24]=1;
	/*=============3ª PARTE=============*/

	/*========4ª PARTE 'CUBO'==========*/
        universo[linha+2][coluna+34]=1;
        universo[linha+3][coluna+34]=1;
        universo[linha+2][coluna+35]=1;
        universo[linha+3][coluna+35]=1;
	/*========4ª PARTE 'CUBO'==========*/

        }
        verificador=0;
    }
    /*=======================POVOAMENTO GOSPER GLIDER GUN================================*/
}

void matriz_geracoes(matriz universo, int ordem_da_matriz){

    /*==================CRIANDO GERACOES=====================*/
    int i,j;//contadores (linha,coluna) para o for
    int k;//contador ate geracao
    int timer;//ira contador_visinhasar ate 3 milhoes para que o usuario teha tempo de ver o desenvolvimento
    int contador_visinhas=0;//contara quantas universo vizinhas vivas ou mortas
    matriz universo_proxima_geracao;//ira armazenar a proxima geracao/**==========*/
    int x,y,z;
    for(i=0;i<MAXL;i++){
        for(j=0;j<MAXL;j++){
            universo_proxima_geracao[i][j]=0;
        }
    }
    int geracoes;
    /*======================PEDIR GERACOES========================*/
        do{
            system("cls");
            imprimir_matriz_estatica(universo,ordem_da_matriz);
            printf("Digite quantas geracoes voce deseja ver (De 2 ate 10000).\n");
            scanf("%i",&geracoes);
        }while((geracoes<2)||(geracoes>10000));
    /*======================PEDIR GERACOES========================*/
    for(k=geracoes;k>0;k--){
        for(i=1;i<ordem_da_matriz;i++){
            for(j=1;j<ordem_da_matriz;j++){

                //verificando celulas vivas
                if(universo[i-1][j-1] == 1 ) {
                     contador_visinhas++;
                 }
                 if(universo[i-1][j] == 1 ) {
                     contador_visinhas++;
                 }
                 if(universo[i-1][j+1] == 1 ) {
                     contador_visinhas++;
                 }
                 if(universo[i][j-1] == 1 ) {
                     contador_visinhas++;
                 }
                 if(universo[i][j+1] == 1 ) {
                     contador_visinhas++;
                 }
                 if(universo[i+1][j-1] == 1) {
                     contador_visinhas++;
                 }
                 if(universo[i+1][j] == 1 ) {
                     contador_visinhas++;
                 }
                 if(universo[i+1][j+1] == 1) {
                     contador_visinhas++;
                 }

                 // povoando a proxima geracao
                 if((contador_visinhas == 0) && (universo[i][j] == 1)) {
                         universo_proxima_geracao[i][j] = 0;
                 }
                 if((contador_visinhas == 1) && (universo[i][j] == 1)) {
                         universo_proxima_geracao[i][j] = 0;
                 }
                 if((contador_visinhas == 2) && (universo[i][j] == 1)) {
                        universo_proxima_geracao[i][j] = 1;
                 }
                 if((contador_visinhas == 3) && (universo[i][j] == 0)) {
                        universo_proxima_geracao[i][j] = 1;
                 }
                 if((contador_visinhas == 3) && (universo[i][j] == 1)) {
                        universo_proxima_geracao[i][j] = 1;
                 }
                 if((contador_visinhas >= 4) && (universo[i][j] == 1)) {
                        universo_proxima_geracao[i][j] = 0;
                 }
                 contador_visinhas=0;
            }

        }
        system("cls");
        /*IMPRIMIR MATRIZ*/
        imprimir_matriz_estatica(universo_proxima_geracao,ordem_da_matriz);
        /*IMPRIMIR MATRIZ*/
        system("cls");
        /*TEMPORIZADOR PARA DAR TEMPO DO USUARIO */
        for(y=0;y<2000;){
            y++;
       }
       /*TEMPORIZADOR PARA DAR TEMPO DO USUARIO */
       /* ATUALIZANDO A GERACAO ANTERIOR*/
       for(x=0;x<ordem_da_matriz;x++){
            for(z=0;z<ordem_da_matriz;z++){
                universo[x][z]=universo_proxima_geracao[x][z];
            }
       }
       /* ATUALIZANDO A GERACAO ANTERIOR*/
    }
    menu(universo_proxima_geracao,ordem_da_matriz);
}

int main(){
    criacao_anulacao_do_universo();
    system("pause");
    return 0;
}
