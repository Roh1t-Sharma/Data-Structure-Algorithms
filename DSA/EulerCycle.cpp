#include <iostream>
#include <vector>
using namespace std;

// function to find Euler cycle in a graph
vector<int> find_euler_cycle(vector<vector<int> > G) {
    int n = G.size();  // number of vertices in G
    vector<int> C;     // current cycle being constructed
    vector<vector<int> > H = G;  // copy of G
    if (n == 0) {
        return C;  // empty graph has no Euler cycle
    }
    // check if G is connected
void dfs(vector<vector<int> >& G, vector<bool>& visited, int u) {
    visited[u] = true;
    for (int v : G[u]) {
        if (!visited[v]) {
            dfs(G, visited, v);
        }
    }
}

    // check if all vertices have even degree
    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) {
            deg += H[i][j];
        }
        if (deg % 2 != 0) {
            return C;  // some vertex has odd degree, so no Euler cycle exists
        }
    }
    // construct Euler cycle
    int curr = start;
    C.push_back(curr);
    while (true) {
        int next = -1;
        for (int i = 0; i < n; i++) {
            if (H[curr][i] > 0) {
                next = i;
                break;
            }
        }
        if (next == -1) {
            break;  // no more edges to traverse
        }
        C.push_back(next);
        H[curr][next] = H[next][curr] = 0;  // remove edge from H
        curr = next;
    }
    // check if all edges have been used
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (H[i][j] > 0) {
                return vector<int>();  // some edge has not been used, so no Euler cycle exists
            }
        }
    }
    return C;  // Euler cycle found!
}

// depth-first search algorithm
void dfs(vector<vector<int> > G, vector<bool>& visited, int u) {
    visited[u] = true;
    for (int v = 0; v < G.size(); v++) {
        if (G[u][v] > 0 && !visited[v]) {
            dfs(G, visited, v);
        }
    }
}

// sample usage
int main() {
    // create sample graph
    vector<vector<int> > G = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    vector<int> cycle = find_euler_cycle(G);
    if (cycle.size() == 0) {
        cout << "No Euler cycle exists" << endl;
    } else {
        cout << "Euler cycle: ";
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
    return 0;
}