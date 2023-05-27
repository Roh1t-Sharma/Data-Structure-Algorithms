#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1e9;

int prim(int start, vector<vector<pair<int, int> > >& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(graph.size(), INF);
    vector<bool> visited(graph.size(), false);
    dist[start] = 0;
    pq.push(make_pair(0, start));
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        totalWeight += dist[u];

        for (vector<pair<int, int> >::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
            int v = (*it).first;
            int weight = (*it).second;

            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int start = 0;
    int minWeight = prim(start, graph);

    cout << "Minimum weight: " << minWeight << endl;
    return 0;
}
