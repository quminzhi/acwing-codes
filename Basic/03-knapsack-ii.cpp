#include <iostream>
#include <vector>
using namespace std;

// each item can be used as many times as we want.
//
// f[i][j] = f[i - 1][j], if ith item is not selected,
//         = f[i][j - v[i]] + w[i], if ith item is selected
//
// ==>
//
// f[j] = f[j]
//      = f[j - v[i]] + w[i], but scanning from left to right
// since f[i] relies on f[i], not f[i - 1]

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }

  vector<int> f(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = v[i]; j <= m; j++) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }

  cout << f[m] << endl;

  return 0;
}
