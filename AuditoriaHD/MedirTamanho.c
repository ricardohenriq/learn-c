/*
https://allanlima.wordpress.com/2006/07/15/calculando-o-tamanho-de-um-arquivo-em-c-2/
fseek - movimenta a posição corrente de escrita ou leitura no 
arquivo para um local específico
ftell – retorna a posição corrente de leitura ou escrita no 
arquivo (em bytes)

A idéia é simples, primeiro movimentamos a posição 
corrente de escrita ou leitura no arquivo para o seu fim, 
com a função fseek em seguida, chamamos a função ftell para 
sabermos qual é posição atual de leitura ou escrita no arquivo, 
neste ponto a função ftell irá retornar quantos bytes o 
arquivo possui.
*/
#include <stdio.h>
 
int main() {
 
    char nomeArquivo[100]; // nome do arquivo
    FILE *arquivo; // ponteiro para o arquivo
    long tamanho; // tamanho em bytes do arquivo
     
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);
 
    // abre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");
 
    // verifica se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // movimenta a posição corrente de leitura no arquivo 
        // para o seu fim
        fseek(arquivo, 0, SEEK_END);
 
        // pega a posição corrente de leitura no arquivo
        tamanho = ftell(arquivo);
 
        // imprime o tamanho do arquivo
        printf("O arquivo %s possui %ld bytes", nomeArquivo, tamanho);
     
    } else {
        printf("Arquivo inexistente");
    }
	//LEMBRAR DE FECHAR O ARQUIVO
    return 0;
 
}

/*
Como a função fseek altera o estado do arquivo, para 
criarmos uma função que calcular o tamanho de um 
arquivo devemos guardar o estado do arquivo antes da 
função ser chamada para, depois poderemos recuperá-lo.
*/

/*
long calcularTamanhoArquivo(FILE *arquivo) {
 
    // guarda o estado ante de chamar a função fseek
    long posicaoAtual = ftell(arquivo);
 
    // guarda tamanho do arquivo
    long tamanho;
 
    // calcula o tamanho
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
 
    // recupera o estado antigo do arquivo
    fseek(arquivo, posicaoAtual, SEEK_SET);
 
    return tamanho;
}

*/