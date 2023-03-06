#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// same as climbing mountains.

int main() {
  int n;
  cin >> n;

  int nums[n];
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int f[n];
  memset(f, 0, sizeof f);

  for (int i = 0; i < n; i++) {
    f[i] = 1;
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
  }

  int g[n];
  memset(g, 0, sizeof g);

  for (int i = n - 1; i >= 0; i--) {
    g[i] = 1;
    for (int j = n - 1; j >= 0; j--) {
      if (nums[j] < nums[i]) {
        g[i] = max(g[i], g[j] + 1);
      }
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, f[i] + g[i]);
  }
  res--;

  cout << n - res << endl;

  return 0;
}
