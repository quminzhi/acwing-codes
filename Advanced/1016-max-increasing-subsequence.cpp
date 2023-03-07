#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// f[i] represents the maximum increasing subsequence ending with nums[i]
//
// f[i] = max(f[i], f[j] + nums[i]) if nums[j] < nums[i]

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int res = 0;
  int f[n];
  memset(f, 0, sizeof f);
  for (int i = 0; i < n; i++) {
    f[i] = nums[i];
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        f[i] = max(f[i], f[j] + nums[i]);
      }
    }
    res = max(res, f[i]);
  }

  cout << res << endl;

  return 0;
}
