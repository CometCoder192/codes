#include <iostream>
using namespace std;

const int size = 20;
int visited[size];

class Stack {
    int a[size], top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        a[++top] = x;
    }

    int pop() {
        return a[top--];
    }

    int empty() {
        if (top == -1)
            return 1;
        else
            return 0;
    }
};

void nonrec_dfs(int g[size][size], int n, int s) {
    Stack s1;
    int cn;

    s1.push(s);

    while (!s1.empty()) {
        cn = s1.pop();

        if (!visited[cn]) {
            cout << cn + 1 << "\t ";
            visited[cn] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (g[cn][i] == 1 && !visited[i])
                s1.push(i);
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

    cout << "DFS Traversal: ";
    nonrec_dfs(g, n, start - 1);

    return 0;
}