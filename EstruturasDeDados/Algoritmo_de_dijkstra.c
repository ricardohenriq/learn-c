#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
// Quantidade m�xima de vertices
const int MAXV = 501;
// Matriz de adjac�ncia
int grafo[MAXV][MAXV];
int dijkstra(int origem, int destino, int v)
{
    int i, minimo, atual;
    int custo[MAXV];
    bool passou[MAXV];
    for (i = 0; i < v; i++)
    {
        passou[i] = false;
        custo[i] = INF;
    }
    custo[origem] = 0;
    atual = origem;
    while (atual != destino)
    {
        for (i = 0; i < v; i++)
            if (grafo[atual][i] != -1)
                if (custo[atual] + grafo[atual][i] < custo[i])
                    custo[i] = custo[atual] + grafo[atual][i];
        minimo = INF + 1;
        passou[atual] = true;
        for (i = 0; i < v; i++)
            if ((custo[i] < minimo) && (!passou[i]))
            {
                minimo = custo[i];
                atual = i;
            }
        if (minimo >= INF)
            return INF;
    }
    return custo[destino];
}
int main()
{
    int vertices, arestas;
    while (scanf("%d %d", &vertices, &arestas) && vertices)
    {
        memset(grafo, 0xff, sizeof(grafo)); // 0xffffffff = -1
        for (int i = 0; i < arestas; i++)
        {
            int x, y, horas;
            scanf("%d %d %d", &x, &y, &horas);
            grafo[x - 1][y - 1] = horas;
            if (grafo[y - 1][x - 1] != -1) // mesma cidade
                grafo[x - 1][y - 1] = grafo[y - 1][x - 1] = 0;
        }
        int consultas;
        scanf("%d", &consultas);
        for (int i = 0; i < consultas; i++)
        {
            int orig, dest;
            scanf("%d %d", &orig, &dest);
            int dist = dijkstra(orig - 1, dest - 1, vertices);
            if (dist >= INF)
                puts("Nao e possivel entregar a carta");
            else
                printf("%d\n", dist);
        }
        putchar('\n');
    }
    return 0;
}
