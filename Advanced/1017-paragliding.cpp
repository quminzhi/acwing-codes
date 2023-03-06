#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// longest increasing subsequences from left to right and right to left.

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    int nums[n];
    memset(nums, 0, sizeof nums);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    int res = 0;
    int f[n];
    memset(f, 0, sizeof f);

    for (int i = 0; i < n; i++) {
      f[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          f[i] = max(f[i], f[j] + 1);
        }
      }
      res = max(res, f[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
      f[i] = 1;
      for (int j = n - 1; j > i; j--) {
        if (nums[j] < nums[i]) {
          f[i] = max(f[i], f[j] + 1);
        }
      }
      res = max(res, f[i]);
    }

    cout << res << endl;
  }

  return 0;
}
