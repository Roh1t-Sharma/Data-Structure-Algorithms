#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void create_matrix(int vertices, int edges, vector<vector<int> > &matrix, bool directed = false) {
    // Initialize the matrix with infinite values
    matrix.resize(vertices, vector<int>(vertices, INF));
    
    int vertex1, vertex2, cost;
    for (int i = 0; i < edges; i++) {
        // Read the edge/arc parameters: vertex1, vertex2, and cost
        cin >> vertex1 >> vertex2 >> cost;
        // Set the cost of the edge/arc
        matrix[vertex1][vertex2] = cost;
        // If the graph is undirected, set the reverse edge/arc as well
        if (!directed) {
            matrix[vertex2][vertex1] = cost;
        }
    }
}

int main() {
    int vertices, edges;
    // Read the number of vertices and edges
    cin >> vertices >> edges;
    vector<vector<int> > matrix;
    // Call the function to create the matrix
    create_matrix(vertices, edges, matrix);
    // Print the matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
