#include <stdio.h>
#include <stdlib.h>
#define Vertex int

/*
======================================
     DIGRAFO MATRIZ DE ADJACENCIA
======================================
*/

/* Um objeto do tipo Digraph contém o endereço de um
digraph. */
typedef struct digraph *Digraph;

/* Vamos supor que nossos digrafos têm no máximo maxV vértices. */
#define maxV 10000
int conta, pre[maxV],pos[maxV],lbl[maxV],cc[maxV];
Vertex parent[maxV];

/* A estrutura digraph representa um digrafo. O campo adj é um
ponteiro para a matriz de adjacência do digrafo. O campo V
contém o número de vértices e o campo A contém o número de
arcos do digrafo. */
struct digraph {
   int V;
   int A;
   int **adj;
};

/* Esta função aloca uma matriz com linhas 0..r-1 e colunas
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

/* Esta função insere um arco v-w no digrafo G. A função
supõe que v e w são distintos, não negativos e menores
que G->V. Se o digrafo já tem arco v-w, a função não faz
nada. */
void DIGRAPHinsertA( Digraph G, Vertex v, Vertex w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->A++;
   }
}

/* Para cada vértice v do digrafo G, esta função imprime,
em uma linha, todos os vértices adjacentes a v. */
void DIGRAPHshow( Digraph G) {
    Vertex v, w;
    for (v = 0; v < G->V; v++) {
        printf( "%d:", v);
        for (w = 0; w < G->V; w++)
            if (G->adj[v][w] == 1)
    printf( " %d", w);
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

/* A função dfsR supõe que o digrafo G é representado
por uma matriz de adjacência.(Inspirado no programas
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

/* A função DIGRAPHdfs visita todos os vértices e todos
os arcos do digrafo G. A função atribui um número de
ordem pre[x] a cada vértice x:  o k-ésimo vértice visitado
recebe número de ordem k. Código inspirado no programa 18.3
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

/* A função pathR visita todos os vértices que podem ser
atingidos a partir de v sem passar por vértices cujo rótulo
lbl é 0. */
void pathROriginal( Digraph G, Vertex v) {
   Vertex w;
   lbl[v] = 1;
   for (w = 0; w < G->V; w++)
      if (G->adj[v][w] == 1 && lbl[w] == 0){
        parent[w] = v;
         pathROriginal( G, w);
      }
}

/* A função abaixo recebe vértices s e t de um digrafo G
representado por sua matriz de adjacência e devolve 1 se
existe um caminho de s a t ou devolve 0 em caso contrário. */
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

int main(){

    int caso;
    int QTDEvertices,QTDEarcos;
    int verticeInicio,verticeFim;
    int i,j;
    scanf("%i",&caso);
    for(i = 0;i < caso; i++){
        scanf("%i %i",&QTDEvertices, &QTDEarcos);
        Digraph grafo = DIGRAPHinit(QTDEvertices);
        for(j = 0; j < QTDEarcos; j++){
            scanf("%d %d",&verticeInicio,&verticeFim);
            DIGRAPHinsertA( grafo, verticeInicio, verticeFim);

        }
        printf("Caso %i:\n",i+1);
        DIGRAPHdfs(grafo);
        imprimePre(grafo);
        printf("\n");
        imprimePos(grafo);
    }
    return 0;
}
