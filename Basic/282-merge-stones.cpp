#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int getSum(vector<int> &presum, int l, int r) {
  return presum[r] - presum[l - 1];
}

int main() {
  int n;
  cin >> n;

  vector<int> stones(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> stones[i];
  }

  // 1-based
  vector<int> presum(n + 1);
  for (int i = 1; i <= n; i++) {
    presum[i] = presum[i - 1] + stones[i];
  }

  int f[n + 1][n + 1];
  memset(f, 0x3f, sizeof f);

  for (int len = 1; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      if (len == 1)
        f[l][r] = 0;
      else {
        // split into two parts, [l, k] and [k + 1, r]
        for (int k = l; k < r; k++) {
          f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + getSum(presum, l, r));
        }
      }
    }
  }

  cout << f[1][n] << endl;

  return 0;
}
