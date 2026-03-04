#include <iostream>
using namespace std;

const int size = 20;
const int MAX = 999;

int visited[size], parent[size], key[size];

int findmin(int n) {

    int i, j, min;
    min = MAX;

    for (i = 0; i < n; i++) {
        if (key[i] < min && !visited[i]) {
            min = key[i];
            j = i;
        }
    }

    return j;
}

void prim(int g[size][size], int n) {

    int i, j, u;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
        key[i] = MAX;

    parent[0] = -1;
    key[0] = 0;

    while (n - 1 > 0) {

        u = findmin(n);
        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (g[u][j] != 0 && !visited[j]) {
                if (g[u][j] < key[j]) {
                    key[j] = g[u][j];
                    parent[j] = u;
                }
            }
        }

        n--;
    }
}

int main() {

    int g[size][size], n, i, j;

    cin >> n;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> g[i][j];

    prim(g, n);

    for (i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " = " << key[i] << endl;

    return 0;
}