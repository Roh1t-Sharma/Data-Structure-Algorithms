#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool check_connected(unordered_map<int, vector<int> >& graph) {
    int start_vertex = graph.begin()->first;
    unordered_map<int, bool> visited;
    for (auto& pair : graph) {
        visited[pair.first] = false;
    }
    vector<int> stack = { start_vertex };
    while (!stack.empty()) {
        int vertex = stack.back();
        stack.pop_back();
        visited[vertex] = true;
        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                stack.push_back(neighbor);
            }
        }
    }
    for (auto& pair : visited) {
        if (!pair.second) {
            return false;
        }
    }
    return true;
}

bool check_even_degrees(unordered_map<int, vector<int> >& graph) {
    for (auto& pair : graph) {
        if (pair.second.size() % 2 != 0) {
            return false;
        }
    }
    return true;
}

vector<int> euler_cycle(unordered_map<int, vector<int> >& graph) {
    // Step 1: Verify that the graph is connected.
    bool connected = check_connected(graph);
    if (!connected) {
        return {};
    }

    // Step 2: Check if every vertex in the graph has an even degree.
    bool even_degrees = check_even_degrees(graph);
    if (!even_degrees) {
        return {};
    }

    // Step 3: Choose any vertex as a starting point.
    int start_vertex = graph.begin()->first;

    // Step 4: Follow any edge out of the starting vertex to a new vertex and remove that edge from the graph.
    vector<int> cycle;
    vector<int> stack = { start_vertex };
    while (!stack.empty()) {
        int vertex = stack.back();
        if (!graph[vertex].empty()) {
            int next_vertex = graph[vertex].back();
            graph[vertex].pop_back();
            graph[next_vertex].erase(remove(graph[next_vertex].begin(), graph[next_vertex].end(), vertex), graph[next_vertex].end());
            stack.push_back(next_vertex);
        }
        else {
            cycle.push_back(vertex);
            stack.pop_back();
        }
    }

    // Step 5: Repeat step 4 until you cannot move to a new vertex anymore.
    // Step 6: If there are remaining edges in the graph, choose one of the vertices in the current cycle
    //         that still has unused edges and repeat steps 4-6 from that vertex.
    for (auto it = cycle.rbegin(); it != cycle.rend(); ++it) {
        if (!graph[*it].empty()) {
            int index = it - cycle.rbegin();
            auto new_cycle = euler_cycle(graph);
            if (new_cycle.empty()) {
                return {};
            }
            cycle.erase(cycle.begin() + index, cycle.end() - cycle.size() + index + 1);
            cycle.insert(cycle.end() - cycle.size() + index, new_cycle.begin(), new_cycle.end());
        }
    }

    // If all edges have been used in the process, then the resulting sequence of vertices and edges forms an Euler cycle.
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

int main() {
     unordered_map<int, vector<int> > graph = {
        { 1, {2, 3, 4} },
        { 2, {1, 3, 4} },
        { 3, {1, 2, 4} },
        { 4, {1, 2, 3} }
    };
    
    vector<int> cycle = euler_cycle(graph);
    if (cycle.empty()) {
        cout << "No Euler cycle exists." << endl;
    }
    else {
        cout << "Euler cycle: ";
        for (int vertex : cycle) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
