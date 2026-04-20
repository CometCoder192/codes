#include <iostream>
using namespace std;

const int MAX = 50;  
int visited[MAX];


//DFS
void dfs(int gr[MAX][MAX], int n, int s){
    visited[s] = 1;
    cout << s << " -> ";

    for(int i = 0; i < n; i++){
        if(gr[s][i] == 1 && !visited[i]){
            dfs(gr, n, i);
        }
    }
}



class Queue {
    int front, rear;
    int arr[MAX];

public:
    Queue(){
        front = rear = -1;
    }

    bool empty(){
        if(front == -1 || front > rear)
            return true;
        return false;
    }

    void insert(int x){
        if(rear == MAX-1){
            cout << "queue overflow\n";
            return;
        }

        if(front == -1)
            front = 0;

        arr[++rear] = x;
    }

    int delitem(){
        if(empty())
            return -1;

        return arr[front++];
    }
};


//BFS
void bfs(int g[MAX][MAX], int n, Queue &q){
    if(q.empty())
        return;

    int cn = q.delitem();

    for(int i = 0; i < n; i++){
        if(g[cn][i] == 1 && !visited[i]){
            cout << i << " -> ";
            visited[i] = 1;
            q.insert(i);
        }
    }

    bfs(g, n, q);
}


// ---------- MAIN ----------
int main(){
    int g[MAX][MAX];
    int i, j, n, start;

    cout << "Enter no. of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> g[i][j];
        }
    }

    cout << "Enter starting node: ";
    cin >> start;

    // ----- DFS -----
    for(i=0;i<n;i++)
        visited[i] = 0;

    cout << "DFS Traversal: ";
    dfs(g, n, start);

    // ----- BFS -----
    for(i=0;i<n;i++)
        visited[i] = 0;

    Queue q;
    q.insert(start);
    visited[start] = 1;

    cout << "\nBFS Traversal: " << start << " -> ";
    bfs(g, n, q);

    return 0;
}