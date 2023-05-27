#include <iostream>
#include <vector>

using namespace std;

// Function to convert adjacency matrix to adjacency vector
vector<vector<int> > adjMatrixToVector(int** adjMatrix, int n) {
    vector<vector<int> > adjVector(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                adjVector[i].push_back(j);
            }
        }
    }
    return adjVector;
}

// Function to convert adjacency vector to adjacency matrix
int** adjVectorToMatrix(vector<vector<int> > adjVector) {
    int n = adjVector.size();
    int** adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
        for (int j = 0; j < adjVector[i].size(); j++) {
            adjMatrix[i][adjVector[i][j]] = 1;
        }
    }
    return adjMatrix;
}

// Function to convert list of edges to adjacency matrix
int** edgesToList(int** adjMatrix, int n) {
    int numEdges = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                numEdges++;
            }
        }
    }
    int** edgeList = new int*[numEdges];
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                edgeList[count] = new int[2];
                edgeList[count][0] = i;
                edgeList[count][1] = j;
                count++;
            }
        }
    }
    return edgeList;
}

// Function to convert list of edges to adjacency matrix
int** listToEdges(int** edgeList, int n, int numEdges) {
    int** adjMatrix = new int*[n]();
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < numEdges; i++) {
        adjMatrix[edgeList[i][0]][edgeList[i][1]] = 1;
        adjMatrix[edgeList[i][1]][edgeList[i][0]] = 1;
    }
    return adjMatrix;
}

// Driver code
int main() {
    int n = 5;
    int** adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][3] = adjMatrix[3][0] = 1;
    adjMatrix[1][2] = adjMatrix[2][1] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;
    adjMatrix[2][4] = adjMatrix[4][2] = 1;
    adjMatrix[3][4] = adjMatrix[4][3] = 1;

// Convert adjacency matrix to adjacency vector
vector<vector<int> > adjVector = adjMatrixToVector(adjMatrix, n);
printAdjVector(adjVector);

// Convert adjacency vector to list of edges
vector<pair<int, int> > edges = edgesToList(adjVector);
cout << Edges(edges);

// Convert list of edges to adjacency matrix
int** adjMatrix2 = edgesToAdjMatrix(edges, n);
printAdjMatrix(adjMatrix2, n);

// Convert adjacency matrix to adjacency list
vector<vector<int> > adjList = adjMatrixToAdjList(adjMatrix, n);
printAdjList(adjList);

return 0;
}