#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int res = 0;
  vector<int> f(n, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }

    res = max(res, f[i]);
  }

  cout << res << endl;

  return 0;
}
