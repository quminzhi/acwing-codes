#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// f[i][j] represents the maximum number of peanut picked up from (0, 0) to (i,
// j)

int main() {
  int T;
  cin >> T;

  while (T--) {
    int m, n;
    cin >> m >> n;

    int f[m + 1][n + 1];
    memset(f, 0, sizeof f);

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> f[i][j];
      }
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] += max(f[i - 1][j], f[i][j - 1]);
      }
    }

    cout << f[m][n] << endl;
  }

  return 0;
}
