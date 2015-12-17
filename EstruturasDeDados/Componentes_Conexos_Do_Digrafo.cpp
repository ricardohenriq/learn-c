#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define Vertex char
#define FIRST_CHAR 97 //Número do caracter 'a'


using namespace std;

typedef struct{
	int vertices;
	int arestas;
	
	int **matriz;
	
} Digraph;

int **MatrizInit(int vertices){
	int i, j;
	
	int **m = (int **) malloc(vertices * sizeof(int*));
	
	for(i = 0; i < vertices; i++){
		m[i] = (int *) malloc(vertices * sizeof(int));
	}
	
	for(i = 0; i < vertices; i++){
		for(j = 0; j < vertices; j++){
			m[i][j] = 0;
		}
	}
	
	return m;
}

Digraph DigraphInit(int vertices){
	Digraph grafo;
	
	grafo.vertices = vertices;
	grafo.arestas = 0;
	grafo.matriz = MatrizInit(vertices);
	
	return grafo;
}

void DigraphInsert(Digraph grafo, Vertex origem, Vertex final){
	if(grafo.matriz[origem - FIRST_CHAR][final - FIRST_CHAR] == 0){
		grafo.matriz[origem - FIRST_CHAR][final - FIRST_CHAR] = 1;
		grafo.matriz[final - FIRST_CHAR][origem - FIRST_CHAR] = 1;
		grafo.arestas++;
		grafo.arestas++;
	}
}

static int cc[26];
static char componentes[26];
static int contador;

void dfsRcc(Digraph grafo, int vertice, int vizinho, int id){
	cc[vertice] = id;
	//printf("%c,", (vertice + FIRST_CHAR));
	componentes[contador++] = vertice + FIRST_CHAR;
	for(int n = 0; n < grafo.vertices; n++){
		if(grafo.matriz[vertice][n] == 1 && cc[n] == -1){
			dfsRcc(grafo, n, vizinho, id);
		}
	}
}

void limpar_componentes(){
	contador = 0;
	for(int i=0; i<26; i++){
		componentes[i] = 0;
	}
}

void imprimir_ordenado(){
	for(int i = 0; componentes[i] != 0; i++){
		for(int j = 0; componentes[j] != 0; j++){
			if(componentes[i]<componentes[j]){
				char aux = componentes[i];
				componentes[i] = componentes[j];
				componentes[j] = aux;
			}
		}
	}
	for(int i = 0; componentes[i] != 0; i++){
		printf("%c,", componentes[i]);
	}
	
}

void GraphCC(Digraph grafo){
	int id = 0;
	
	for(int vertice = 0; vertice < grafo.vertices; vertice++){
		cc[vertice] = -1;
	}
	
	for(int vertice = 0; vertice < grafo.vertices; vertice++){
		for(int vizinho = 0; vizinho < grafo.vertices; vizinho++){
			if(cc[vertice] == -1){
				limpar_componentes();
				dfsRcc(grafo, vertice, vizinho, id++);
				imprimir_ordenado();
				printf("\n");
			}
		}
	}
	
	printf("%d connected components\n", id);
}


int main(){
	int n, v, e;
	Vertex u, w;
	scanf("%d", &n);
	
	for(int teste = 0; teste < n; teste++){
		scanf("%d %d", &v, &e);
		
		Digraph digraph = DigraphInit(v);
		
		for(int aresta = 0; aresta < e; aresta++){
			//scanf("%c %c", u, &w);
			cin >> u >> w;
			//printf("u = %c, w = %c\n", u, w);
			
			DigraphInsert(digraph, u, w);
		}
		printf("Case #%d:\n", teste+1);
		GraphCC(digraph);
		//if(teste < n -1){
			printf("\n");
		//}
	}
	//printf("\n\n");
	
}
