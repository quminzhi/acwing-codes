#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// knapsack problem with limited items
//
// f[i][j] = f[i - 1][j], f[i - 1][j - 1 * v[i]] + 1 * w[i], ..., f[i - 1][j - s
// * v[i]] + s * w[i]

int main() {
  int n, m;
  cin >> n >> m;

  int v[n + 1], w[n + 1], s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> s[i];
  }

  int f[m + 1];
  memset(f, 0, sizeof f);

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 0; j--) {
      for (int k = 0; k <= s[i]; k++) {
        if (j - v[i] * k < 0)
          continue;
        f[j] = max(f[j], f[j - v[i] * k] + w[i] * k);
      }
    }
  }

  cout << f[m] << endl;

  return 0;
}
