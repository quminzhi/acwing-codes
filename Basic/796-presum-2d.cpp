#include <iostream>
#include <vector>
using namespace std;

int main() {
  int m, n, k;
  cin >> m >> n >> k;

  vector<vector<int>> g(m + 1, vector<int>(n + 1));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> g[i][j];
    }
  }

  // convert to presum matrix
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
    }
  }

  while (k--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int sum = g[x][y] - g[x][b - 1] - g[a - 1][y] + g[a - 1][b - 1];
    cout << sum << endl;
  }

  return 0;
}
