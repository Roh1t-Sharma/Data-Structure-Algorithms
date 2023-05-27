#include <iostream>
#include <vector>
using namespace std;

void reachability_matrix(int vertices, vector<vector<int> > &adj_matrix, vector<vector<int> > &reach_matrix) {
  reach_matrix = adj_matrix;
  for (int k = 0; k < vertices; k++) {
    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        reach_matrix[i][j] = reach_matrix[i][j] || (reach_matrix[i][k] && reach_matrix[k][j]);
      }
    }
  }
}

int main() {
  int vertices;
  cin >> vertices;
  vector<vector<int> > adj_matrix(vertices, vector<int>(vertices));
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      cin >> adj_matrix[i][j];
    }
  }
  vector<vector<int> > reach_matrix;
  reachability_matrix(vertices, adj_matrix, reach_matrix);
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      cout << reach_matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
