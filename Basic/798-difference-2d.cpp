#include <iostream>
#include <vector>
using namespace std;

// similar to 2-d presum (mirror)
// assumed that a <= x and b <= y
void insert(vector<vector<int>> &g, int a, int b, int x, int y, int add) {
  g[a][b] += add;
  g[x + 1][b] -= add;
  g[a][y + 1] -= add;
  g[x + 1][y + 1] += add;
}

int main() {
  int m, n, k;
  cin >> m >> n >> k;

  // same as 1-d difference, add overflow column and row
  // 0-based matrix
  vector<vector<int>> g(m + 1, vector<int>(n + 1));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      insert(g, i, j, i, j, x);
    }
  }

  while (k--) {
    int a, b, x, y, add;
    cin >> a >> b >> x >> y >> add;
    a--, b--, x--, y--;
    insert(g, a, b, x, y, add);
  }

  // aggregate
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
