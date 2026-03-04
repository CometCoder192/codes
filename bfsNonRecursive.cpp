#include <iostream>
using namespace std;

const int size = 20;
int visited[size];

class Queue {
    int a[size];
    int r, f;

public:
    Queue() {
        r = -1;
        f = 0;
    }

    void insert(int x);
    int del();

    int empty() {
        if (r == -1 && f == 0)
            return 1;
        else
            return 0;
    }
};

void Queue::insert(int x) {
    a[++r] = x;
}

int Queue::del() {
    return a[f++];
}

void nonrec_bfs(int g[size][size], int n, int s) {
    Queue q;
    int cn;

    q.insert(s);

    while (!q.empty()) {
        cn = q.del();

        if (!visited[cn]) {
            cout << cn << "\t ";
            visited[cn] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (g[cn][i] == 1 && !visited[i])
                q.insert(i);
        }
    }
}

int main() {
    int g[size][size], n, start;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "Enter starting node: ";
    cin >> start;

    cout << "BFS Traversal: ";
    nonrec_bfs(g, n, start);

    return 0;
}