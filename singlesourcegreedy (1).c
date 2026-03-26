#include <stdio.h>
#define MAX 10
#define INF 9999
/* Function to find vertex with minimum distance */
int minDistance(int dist[], int visited[], int n)
{
    int min = INF, index = -1;
int i;
    for ( i = 0; i < n; i++)
    {
        if (visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

/* Dijkstra Algorithm */
void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX], visited[MAX];
int i;
    // Initialization
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;
int count;
    // Main loop
    for (count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);

        if (u == -1) // safety check
            break;

        visited[u] = 1;
int v;
        for ( v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display result
    printf("\nVertex\tDistance from Source\n");
    
    for ( i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

/* Main Function */
int main()
{
    int n, graph[MAX][MAX], src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}

