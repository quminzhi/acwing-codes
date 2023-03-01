#include <iostream>
#include <vector>
using namespace std;

// for each item, enumerate how many of them will be chosen.
// f[i][j] = f[i - 1][j], choose 0
//           f[i - 1][j - v[i]] + w[i], choose 1
//           f[i - 1][j - 2 * v[i]] + 2 * w[i], choose 2
//           ...
//           f[i - 1][j - s * v[i]] + s * w[i], choose s

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1), w(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> s[i];
  }

  vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k * v[i] <= j && k <= s[i]; k++) {
        f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
      }
    }
  }

  cout << f[n][m] << endl;

  return 0;
}
