#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

void displayMatrix(int adj[MAX][MAX], int n) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void DFS(int adj[MAX][MAX], int n, int start, int visited[MAX]) {
    cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i])
            DFS(adj, n, i, visited);
    }
}

void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int adj[MAX][MAX];
    int n, choice, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    do {
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. Depth First Search (DFS)\n";
        cout << "3. Breadth First Search (BFS)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMatrix(adj, n);
                break;

            case 2: {
                int visited[MAX] = {0};
                cout << "Enter starting vertex (0 to " << n-1 << "): ";
                cin >> start;
                cout << "DFS Traversal: ";
                DFS(adj, n, start, visited);
                cout << endl;
                break;
            }

            case 3:
                cout << "Enter starting vertex (0 to " << n-1 << "): ";
                cin >> start;
                cout << "BFS Traversal: ";
                BFS(adj, n, start);
                cout << endl;
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
