#include <iostream>
using namespace std;

struct node {
    int data;
    node* link;
};

const int size = 100;
int visited[size];

void dfs(int g[size][size], int n, int s) {
    visited[s] = 1;
    cout << s << "->";

    for (int i = 0; i < n; i++) {
        if (g[s][i] == 1 && visited[i] == 0) {
            dfs(g, n, i);
        }
    }
}

int main() {
    int gr[size][size];
    int j, n, i, start;

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

    dfs(gr, n, start);

    return 0;
}