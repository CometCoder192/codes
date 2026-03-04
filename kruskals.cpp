#include <iostream>
using namespace std;

const int size = 20;

struct edge {
    int v1, v2, wt;
};

int parent[size];

int find(int k) {
    while (parent[k] != k)
        k = parent[k];
    return k;
}

void union_set(int i, int j) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void sort(edge alledges[], int k) {

    edge temp;

    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {

            if (alledges[j].wt > alledges[j + 1].wt) {

                temp = alledges[j];
                alledges[j] = alledges[j + 1];
                alledges[j + 1] = temp;
            }
        }
    }
}

int main() {

    int g[size][size];
    int n, i, j, mstwt = 0, k = 0;

    edge alledges[size], mst[size];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (g[i][j] != 0) {
                alledges[k].v1 = i;
                alledges[k].v2 = j;
                alledges[k].wt = g[i][j];
                k++;
            }
        }
    }

    sort(alledges, k);

    int m = 0, p, q;

    for (int t = 0; t < k; t++) {

        i = alledges[t].v1;
        j = alledges[t].v2;

        p = find(i);
        q = find(j);

        if (p != q) {

            mst[m].v1 = i;
            mst[m].v2 = j;
            mst[m].wt = alledges[t].wt;

            mstwt += alledges[t].wt;

            union_set(p, q);

            m++;
        }
    }

    cout << "\nEdges in MST:\n";

    for (i = 0; i < m; i++) {
        cout << mst[i].v1 << " - " << mst[i].v2
             << " : " << mst[i].wt << endl;
    }

    cout << "Total MST weight = " << mstwt << endl;

    return 0;
}