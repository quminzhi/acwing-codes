#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// treat n as a knapsack with capacity of n, and we have n items with volume
// from 1 to n and value of 1.
//
// ==> complete knapsack problem

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  int f[n + 1][n + 1];
  memset(f, 0, sizeof f);
  f[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
      if (j >= i) {
        f[i][j] = (f[i][j] + f[i][j - i]) % mod;
      }
    }
  }

  cout << f[n][n] << endl;

  return 0;
}
