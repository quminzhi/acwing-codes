#include <iostream>
#include <vector>
using namespace std;

// f[i][j] represents the longest skiing path starting from (i, j)
//
// f[i][j] = f[i + 1][j] + 1, if height[i + 1][j] < height[i][j]
//         = f[i][j + 1] + 1, ...
//         = f[i - 1][j] + 1, ...
//         = f[i][j - 1] + 1, ...
//
// Search order: dfs

int m, n;
vector<vector<int>> h, f;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int dfs(int x, int y) {
  if (f[x][y] != -1)
    return f[x][y];

  int &v = f[x][y];
  v = 1;

  // try 4 directions
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < m && ny >= 0 && ny < n && h[nx][ny] < h[x][y]) {
      v = max(v, dfs(nx, ny) + 1);
    }
  }

  return v;
}

int main() {
  cin >> m >> n;

  h = vector<vector<int>>(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> h[i][j];
    }
  }

  f = vector<vector<int>>(m, vector<int>(n, -1));
  int res = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      res = max(res, dfs(i, j));
    }
  }

  cout << res << endl;

  return 0;
}
