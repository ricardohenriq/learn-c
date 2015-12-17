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



/* Um objeto do tipo Digraph contém o endereço de um
digraph. */
typedef struct digraph *Digraph;

/* Vamos supor que nossos digrafos têm no máximo maxV vértices. */
#define maxV 10000
int conta, pre[maxV],pos[maxV],lbl[maxV],cc[maxV],somaPesos = 0;
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
   G->adj = MATRIXint( V, V, -1);
   return G;
}

/* Esta função insere um arco v-w no digrafo G. A função
supõe que v e w são distintos, não negativos e menores
que G->V. Se o digrafo já tem arco v-w, a função não faz
nada. */
void DIGRAPHinsertA( Digraph G, Vertex v, Vertex w, int peso) {
   if (G->adj[v][w] == -1) {
      G->adj[v][w] = peso;
      G->A++;
   }
}

/* Para cada vértice v do digrafo G, esta função imprime,
em uma linha, todos os vértices adjacentes a v. */
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
      if (G->adj[v][w] != 0 && lbl[w] == 0){
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
        printf( "%d", s+1);
        while (topo > 0)
           printf( "-%d", pilha[--topo]+1);
        printf( "\n");
}

void somaPesosArestas(Digraph G, Vertex s, Vertex t){
    somaPesos = 0;
    Vertex w, pilha[maxV];
    int caminho[maxV],i=0;
    int topo = 0;
    for (w = t; w != s; w = parent[w])
        pilha[topo++] = w;
    caminho[i] = s;
    while (topo > 0){
        i++;
        caminho[i] = pilha[--topo];
    }
    i++;
    caminho[i] = -1;/**Flag de parada no while abaixo*/
    i=0;
    while(caminho[i+1] != -1){
        if(G->adj[caminho[i+1]][caminho[i]] == 0){
            somaPesos += G->adj[caminho[i]][caminho[i+1]];
            i++;
        }else{
            i++;
        }
    }
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

/* A função DIGRAPHbfs visita todos os vértices do
digrafo G que podem ser alcançados a partir do vértice
s.  A ordem em que os vértices são visitados é registrada
no vetor lbl.  (Código inspirado no programa 18.9 de
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
    int peso; /**peso do arco*/
    int k; /**number of queries*/
    int i,j;

    while(1){
        scanf("%i %i",&QTDEvertices, &QTDEarcos);
        if(QTDEvertices == 0 && QTDEarcos == 0){
            break;
        }
        Digraph grafo = DIGRAPHinit(QTDEvertices);
        for(i = 0; i < QTDEarcos; i++){
            scanf("%d %d %d",&verticeInicio,&verticeFim,&peso);
            DIGRAPHinsertA( grafo, verticeInicio-1, verticeFim-1, peso);
        }
        scanf("%i", &k);
        for(j = 0; j < k; j++){
            scanf("%d %d" ,&verticeInicio,&verticeFim);
            if(DIGRAPHpath(grafo,verticeInicio-1,verticeFim-1)){
                somaPesosArestas(grafo,verticeInicio-1,verticeFim-1);
                printf("%i\n",somaPesos);
            }else{
                printf("Nao e possivel entregar a carta\n");
            }
        }
        printf("\n");
    }
    return 0;
}
