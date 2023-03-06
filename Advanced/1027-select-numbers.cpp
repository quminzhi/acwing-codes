#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

/**
 *  Two path maximum sum
 *
 *  Define f[i1][j1][i2][j2] as maximum sum go from (1, 1) to (i1, j1) and (i2,
 * j2) without picking number from the same cell twice
 *
 *  A better state representation: f[k][i1][i2] given the fact that i1 + j1 ==
 * i2 + j2
 *
 *  we have 4 direction combinations:
 *
 *  from (up, up) (up, left) (left, up) (left, left)
 *
 *  f[k][i1][i2] = max (f[k - 1][i1 - 1][i2 - 1],
 *                      f[k - 1][i1 - 1][i2],
 *                      f[k - 1][i1][i2 - 1],
 *                      f[k - 1][i1][i2])
 *
 *  k = 2 ~ 2 * n
 *    (1,1) (n, n)
 */

int main() {
  int n;
  cin >> n;

  int g[n + 1][n + 1];
  memset(g, 0, sizeof g);

  int a, b, c;
  cin >> a >> b >> c;
  while (a || b || c) {
    g[a][b] = c;
    cin >> a >> b >> c;
  }

  // i1 + j1 == i2 + j2 <= 2 * n
  int f[n + n + 1][n + 1][n + 1];
  memset(f, 0, sizeof f);

  for (int k = 2; k <= n + n; k++) {
    for (int i1 = 1; i1 <= n; i1++) {
      for (int i2 = 1; i2 <= n; i2++) {
        int j1 = k - i1, j2 = k - i2;
        if (j1 < 1 || j1 > n || j2 < 1 || j2 > n)
          continue;

        int &v = f[k][i1][i2];
        v = max(v, f[k - 1][i1 - 1][i2 - 1]); // up up
        v = max(v, f[k - 1][i1 - 1][i2]);     // up left
        v = max(v, f[k - 1][i1][i2 - 1]);     // left up
        v = max(v, f[k - 1][i1][i2]);         // left left

        v += g[i1][j1];
        // prevent from selecting the same cell twice
        if (i1 != i2 || j1 != j2) {
          v += g[i2][j2];
        }
      }
    }
  }

  cout << f[n + n][n][n] << endl;

  return 0;
}
