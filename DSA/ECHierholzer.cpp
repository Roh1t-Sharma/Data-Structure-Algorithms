#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int in_deg[MAXN], out_deg[MAXN];
stack<int> curr_path, circuit;

void euler(int u) {
    curr_path.push(u);
    while (!curr_path.empty()) {
        int v = curr_path.top();
        if (adj[v].empty()) {
            circuit.push(v);
            curr_path.pop();
        } else {
            int nxt = adj[v].back();
            adj[v].pop_back();
            curr_path.push(nxt);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out_deg[u]++, in_deg[v]++;
    }

    int start = -1;
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] != out_deg[i]) {
            cout << "No Euler cycle exists." << endl;
            return 0;
        }
        if (out_deg[i] > 0) {
            start = i;
        }
    }

    euler(start);

    if (circuit.size() != m + 1) {
        cout << "No Euler cycle exists." << endl;
        return 0;
    }

    cout << "Euler cycle exists: ";
    while (!circuit.empty()) {
        cout << circuit.top() << " ";
        circuit.pop();
    }
    cout << endl;

    return 0;
}
