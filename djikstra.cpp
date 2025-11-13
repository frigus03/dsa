#include <iostream>
#include <climits>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;
#define MAX 20

int minDistance(int dist[], bool visited[], int n)
{

    int min = INT_MAX, minIndex;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int start, int n)
{
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distances from vertex " << start << ":\n";

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    int graph[MAX][MAX] = {
    {0, 10, 3, 0, 5},
    {10, 0, 2, 1, 2},
    {3, 2, 0, 7, 0},
    {0, 1, 7, 0, 3},
    {5, 2, 0, 3, 0}
};

    int n = 5;
    int start;
    cout << "Enter the starting vertex (0 to 4): ";
    cin >> start;

    clock_t start_time = clock();
    dijkstra(graph, start, n);
    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    cout << "\nCPU time used for Dijkstra's algorithm: "
<< fixed << setprecision(9) << cpu_time_used << " seconds\n";

    return 0;

}
