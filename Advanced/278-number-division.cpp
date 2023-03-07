#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// f[i][j] = f[i - 1][j] + f[i - 1][j - v[i]]
//
// f[0][0] = 1;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> nums(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }

  sort(nums.begin() + 1, nums.end());

  int f[m + 1];
  memset(f, 0, sizeof f);
  f[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= nums[i]; j--) {
      f[j] += f[j - nums[i]];
    }
  }

  cout << f[m] << endl;

  return 0;
}
