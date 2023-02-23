#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> presum(n + 1);
  for (int i = 1; i <= n; i++) {
    presum[i] = presum[i - 1] + nums[i - 1];
  }

  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << presum[r] - presum[l - 1] << endl;
  }

  return 0;
}
