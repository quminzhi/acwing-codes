#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// limit: volume
// target: min volume left => max valume used

int main() {
  int m, n;
  cin >> m >> n;

  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  int f[m + 1];
  memset(f, 0, sizeof f);

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= v[i]; j--) {
      f[j] = max(f[j], f[j - v[i]] + v[i]);
    }
  }

  cout << m - f[m] << endl;

  return 0;
}
