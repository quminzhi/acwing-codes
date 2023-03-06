#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// same as 1027

int main() {
  int m, n;
  cin >> m >> n;

  int g[m + 1][n + 1];
  memset(g, 0, sizeof g);

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> g[i][j];
    }
  }

  int f[m + n + 1][m + 1][m + 1];
  memset(f, 0, sizeof f);

  for (int k = 2; k <= m + n; k++) {
    for (int i1 = 1; i1 <= m; i1++) {
      for (int i2 = 1; i2 <= m; i2++) {
        int j1 = k - i1, j2 = k - i2;
        if (j1 <= 0 || j1 > n || j2 <= 0 || j2 > n)
          continue;

        int &v = f[k][i1][i2];
        v = max(v, f[k - 1][i1 - 1][i2 - 1]); // up up
        v = max(v, f[k - 1][i1 - 1][i2]);
        v = max(v, f[k - 1][i1][i2 - 1]);
        v = max(v, f[k - 1][i1][i2]);

        v += g[i1][j1];
        if (i1 != i2 || j1 != j2) {
          v += g[i2][j2];
        }
      }
    }
  }

  cout << f[m + n][m][m] << endl;

  return 0;
}
