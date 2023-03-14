#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// f[i][j] means the total number of combinations that make up j with first i
// coins.
//
// f[i][j] += f[i - 1][j], don't use ith coin
//         += f[i][j - coins[i]], use ith coin once
//
// f[0][0] = 1;
//
// => optimization with rolling array
//
// f[j] += f[j]
//      += f[j - coins[i]]
//
// f[0] = 1;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> coins(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> coins[i];
  }

  long f[m + 1];
  memset(f, 0, sizeof f);
  f[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = coins[i]; j <= m; j++) {
      f[j] += f[j - coins[i]];
    }
  }

  cout << f[m] << endl;

  return 0;
}
