#include <iostream>
#include <vector>
using namespace std;

// f[i][j] = f[i - 1][j] if ith item is not selected,
//           f[i - 1][j - v[i]] + w[i] if ith item is selected,
//
// ==> rolling array
//
// f[j] = f[j] if ith item is not selected, (implicit i - 1)
//        f[j - v[i]] + w[i] if ith item is selected (implicit i - 1)
// since f[i] relies on f[i - 1], update from right to left

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }

  vector<int> f(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= v[i]; j--) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }

  cout << f[m] << endl;

  return 0;
}
