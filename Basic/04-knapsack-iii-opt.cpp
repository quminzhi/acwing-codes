#include <iostream>
#include <vector>
using namespace std;

// note f[i][j] only relies on f[i - 1][expr(j)]. It can be optimized
// with a rolling array.

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1), w(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> s[i];
  }

  vector<int> f(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= v[i]; j--) {
      for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
        f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
      }
    }
  }

  cout << f[m] << endl;

  return 0;
}
