#include <iostream>
#include <vector>
using namespace std;

static const int inf = 0x3f3f3f3f;

int firstGE(vector<int> &f, int x) {
  int l = 0, r = f.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (f[mid] >= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  return l;
}

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> f(n + 1, inf); // min val with lis with length of i
  f[0] = -inf;

  for (int i = 0; i < n; i++) {
    int idx = firstGE(f, nums[i]);
    f[idx] = min(f[idx], nums[i]);
  }

  int res = 0;
  for (int i = n; i >= 0; i--) {
    if (f[i] != inf) {
      res = i;
      break;
    }
  }

  cout << res << endl;

  return 0;
}
