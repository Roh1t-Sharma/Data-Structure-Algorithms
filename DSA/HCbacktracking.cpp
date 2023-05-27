#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 20; // maximum number of vertices
int n, m;
bool graph[MAXN][MAXN];

vector<int> path;
bool visited[MAXN];

void backtrack(int v) {
    if (path.size() == n) {
        // check if the last vertex is adjacent to the first vertex
        if (graph[path.back()][path[0]]) {
            cout << "Hamiltonian cycle found: ";
            for (int i = 0; i < n; i++) {
                cout << path[i] << " ";
            }
            cout << path[0] << endl;
        }
        return;
    }
    for (int u = 0; u < n; u++) {
        if (graph[v][u] && !visited[u]) {
            visited[u] = true;
            path.push_back(u);
            backtrack(u);
            path.pop_back();
            visited[u] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = true; 
    }
    
    // initialize starting vertex
    path.push_back(0);
    visited[0] = true;
    
    // start backtracking
    backtrack(0);
    
    cout << "No Hamiltonian cycle found." << endl;
    
    return 0;
}
