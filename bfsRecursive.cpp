#include <iostream>
using namespace std;

const int size = 100;
int visited[size];

void bfs_recursive(int g[size][size], int n, int queue[], int &front, int &rear) {

    if (front == rear)
        return;

    int current = queue[front++];

    cout << current << "->";

    for (int i = 0; i < n; i++) {
        if (g[current][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            queue[rear++] = i;
        }
    }

    bfs_recursive(g, n, queue, front, rear);
}

int main() {

    int gr[size][size];
    int n, i, j, start;

    cout << "Enter no of nodes:";
    cin >> n;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            gr[i][j] = 0;

    cout << "Enter adjacency matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> gr[i][j];

    cout << "Enter starting node:";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting node";
        return 0;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    int queue[size];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    bfs_recursive(gr, n, queue, front, rear);

    return 0;
}