#include <stdio.h>
#include <stdlib.h>
#define Vertex int

/*
======================================
     DIGRAFO MATRIZ DE ADJACENCIA
======================================
*/


/**QUEUE EM C++*/
typedef int Item;
Item *q;
int inicio, fim;

void QUEUEinit(int maxN){
    q = (Item*) malloc(maxN*sizeof(Item));
    inicio = 0;
    fim = 0;
}

int QUEUEempty(){
    return inicio == fim;
}

void QUEUEput(Item item){
    q[fim++] = item;
}

Item QUEUEget(){
    return q[inicio++];
}

void QUEUEfree(){
    free(q);
}



/* Um objeto do tipo Digraph cont�m o endere�o de um
digraph. */
typedef struct digraph *Digraph;

/* Vamos supor que nossos digrafos t�m no m�ximo maxV v�rtices. */
#define maxV 10000
int conta, pre[maxV],pos[maxV],lbl[maxV],cc[maxV];
Vertex parent[maxV];

/* A estrutura digraph representa um digrafo. O campo adj � um
ponteiro para a matriz de adjac�ncia do digrafo. O campo V
cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de
arcos do digrafo. */
struct digraph {
   int V;
   int A;
   int **adj;
};

/* Esta fun��o aloca uma matriz com linhas 0..r-1 e colunas
0..c-1. Cada elemento da matriz recebe valor val. */
int** MATRIXint( int r, int c, int val) {
   Vertex i, j;
   int **m = (int**) malloc( r * sizeof (int *));
   for (i = 0; i < r; i++)
      m[i] = (int*) malloc( c * sizeof (int));
   for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         m[i][j] = val;
   return m;
}

Digraph DIGRAPHinit( int V) {
   Digraph G = (Digraph) malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}

/* Esta fun��o insere um arco v-w no digrafo G. A fun��o
sup�e que v e w s�o distintos, n�o negativos e menores
que G->V. Se o digrafo j� tem arco v-w, a fun��o n�o faz
nada. */
void DIGRAPHinsertA( Digraph G, Vertex v, Vertex w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->A++;
   }
}

/* Para cada v�rtice v do digrafo G, esta fun��o imprime,
em uma linha, todos os v�rtices adjacentes a v. */
void DIGRAPHshow( Digraph G) {
    Vertex v, w;
    for (v = 0; v < G->V; v++) {
        printf( "%d:", v+1);
        for (w = 0; w < G->V; w++)
            if (G->adj[v][w] == 1)
    printf( " %d", w+1);
    printf( "\n");
    }
}

/*funcao utilizada no exercicio de dfs do uri*/
void imprimeEspacos(int numEspacos){
	int contador;
	for (contador = 0; contador < numEspacos; contador++) {
	  printf("  ");
   }
}

/* A fun��o dfsR sup�e que o digrafo G � representado
por uma matriz de adjac�ncia.(Inspirado no programas
18.1 de Sedgewick.) */
void dfsR( Digraph G, Vertex v) {
   Vertex w;
   pre[v] = conta++;
   for (w = 0; w < G->V; w++)
      if (G->adj[v][w] != 0 && pre[w] == -1){
        printf("%i-%i pathR(G,%i)\n",v,w,w);
        parent[w] = v;
        dfsR( G, w);
      }
   //pos[v] = conta++;
}

/* A fun��o DIGRAPHdfs visita todos os v�rtices e todos
os arcos do digrafo G. A fun��o atribui um n�mero de
ordem pre[x] a cada v�rtice x:  o k-�simo v�rtice visitado
recebe n�mero de ordem k. C�digo inspirado no programa 18.3
de Sedgewick.) */
void DIGRAPHdfs( Digraph G) {
   Vertex v;
   conta = 0;
   for (v = 0; v < G->V; v++)
      pre[v] = -1;
   for (v = 0; v < G->V; v++)
      if (pre[v] == -1){
        parent[v] = v;
         dfsR( G, v);
      }
}

void imprimirPreOrdem(Digraph G){
    Vertex preordem[maxV];
     int i,v;

     for (v = 0; v < G->V; ++v)
        preordem[pre[v]] = v;
     for (i = 0; i < G->V; ++i)
        printf( "%d ", preordem[i]);
}

/* A fun��o pathR visita todos os v�rtices que podem ser
atingidos a partir de v sem passar por v�rtices cujo r�tulo
lbl � 0. */
void pathROriginal( Digraph G, Vertex v) {
   Vertex w;
   lbl[v] = 1;
   for (w = 0; w < G->V; w++)
      if (G->adj[v][w] == 1 && lbl[w] == 0){
        parent[w] = v;
         pathROriginal( G, w);
      }
}

/* A fun��o abaixo recebe v�rtices s e t de um digrafo G
representado por sua matriz de adjac�ncia e devolve 1 se
existe um caminho de s a t ou devolve 0 em caso contr�rio. */
int DIGRAPHpath( Digraph G, Vertex s, Vertex t) {
   Vertex v;
   for (v = 0; v < G->V; v++)
      lbl[v] = 0;
   pathROriginal( G, s);
   if (lbl[t] == 0) return 0;
   else return 1;
}

void pathR(Digraph G, Vertex v, int Espacos, Vertex *paths) {
	Vertex w;
	paths[v] = 1;
	for (w = 0; w < G->V; w++) {
	  if (G->adj[v][w] == 1) {
		  imprimeEspacos(Espacos);
		  if (paths[w] == 1) {
			  printf("%d-%d\n", v, w);
		  } else {
			  printf("%d-%d pathR(G,%d)\n", v, w, w);
			  paths[w] = 1;
			  pathR(G, w, Espacos + 1, paths);
		  }
	  }
	}
}

void DIGRAPHpaths( Digraph G) {
   Vertex v, w;
   Vertex paths[G->V];
   for (v = 0; v < G->V; v++) {
	  paths[v] = 0;
   }
   for (v = 0; v < G->V; v++) {
	  if (paths[v] == 0) {
		  pathR(G, v, 1, paths);
		  for (w = 0; w < G->V; w++) {
			if (G->adj[v][w] == 1) {
				printf("\n");
				break;
			}
		  }
	  }
   }
}

void imprimeCaminho( Digraph G, Vertex s, Vertex t) {
        Vertex w, pilha[maxV];
        int topo = 0;
        for (w = t; w != s; w = parent[w])
           pilha[topo++] = w;
        printf( "%d", s);
        while (topo > 0)
           printf( "-%d", pilha[--topo]);
        printf( "\n");
}

void imprimePre(Digraph G){
    int i;
    for(i=0;i<G->V;i++){
        printf("%i - ",pre[i]);
    }
}

void imprimePos(Digraph G){
    int i;
    for(i=0;i<G->V;i++){
        printf("%i - ",pos[i]);
    }
}

/* A fun��o DIGRAPHbfs visita todos os v�rtices do
digrafo G que podem ser alcan�ados a partir do v�rtice
s.  A ordem em que os v�rtices s�o visitados � registrada
no vetor lbl.  (C�digo inspirado no programa 18.9 de
Sedgewick.) */

void DIGRAPHbfs( Digraph G, Vertex s)
{
    Vertex v, w;
    conta = 0;
    for (v = 0; v < G->V; v++)
        lbl[v] = -1;
    QUEUEinit( G->V);
    lbl[s] = conta++;
    QUEUEput( s);
    while (!QUEUEempty( )) {
        v = QUEUEget( );
        for (w = 0; w < G->V; w++){
            if (G->adj[v][w] == 1 && lbl[w] == -1) {
                lbl[w] = conta++;
                QUEUEput( w);
            }
        }
    }
    QUEUEfree( );
}

int main(){

    int QTDEvertices = -1;
    int QTDEarcos = -1;
    int verticeInicio,verticeFim;
    int arcoSimetrico;
    /**Se arcoSimetrico == 1 entao o arco n�o e simetrico
    caso seu valor seja 2 entao ele e simetrico
    existe (v - w e w - v)*/
    int i,j;
    int aux = 0;

    while(1){/**/
        inicio: aux = 0;
        scanf("%i %i",&QTDEvertices, &QTDEarcos);
        if(QTDEvertices == 0 && QTDEarcos == 0){
            break;
        }
        Digraph grafo = DIGRAPHinit(QTDEvertices);
        for(j = 0; j < QTDEarcos; j++){
            scanf("%d %d %d",&verticeInicio,&verticeFim,&arcoSimetrico);
            if(arcoSimetrico == 1){
                DIGRAPHinsertA( grafo, verticeInicio-1, verticeFim-1);
            }else if(arcoSimetrico == 2){
                DIGRAPHinsertA( grafo, verticeInicio-1, verticeFim-1);
                DIGRAPHinsertA( grafo, verticeFim-1, verticeInicio-1);
            }
        }
        /***/
        for(j = 0; j < QTDEvertices; j++){
            DIGRAPHbfs(grafo,j);
            for(i = 0; i < QTDEvertices; i++){
                if(lbl[i] == -1){
                    printf("0\n");
                    aux = 1;
                    goto inicio;
                }
            }
        }
        if(aux == 0){
            printf("1\n");
        }
    }
    return 0;
}
