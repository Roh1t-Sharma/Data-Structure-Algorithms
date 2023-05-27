#include <iostream>
#include <vector>
using namespace std;

const int INF = 2147483647;

void create_matrix(int vertices, int edges, vector<vector<int> > &matrix, bool directed = false) {
  matrix.assign(vertices, vector<int>(vertices, INF));
  for (int i = 0; i < edges; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    matrix[x][y] = z;
    if (!directed) {
      matrix[y][x] = z;
    }
  }
}

int main() {
  int vertices, edges;
  cin >> vertices >> edges;
  vector<vector<int> > matrix;
  create_matrix(vertices, edges, matrix);
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      if (matrix[i][j] == INF) {
        cout << "INF ";
      } else {
        cout << matrix[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
