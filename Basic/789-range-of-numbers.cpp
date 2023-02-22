#include <iostream>
#include <vector>
using namespace std;

void query_range(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] >= target) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  int L = -1, R = -1;
  if (nums[l] == target) {
    L = l;
  } else {
    cout << L << " " << R << endl;
    return;
  }

  l = 0, r = nums.size() - 1;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (nums[mid] <= target) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  R = l;
  cout << L << " " << R << endl;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  while (m--) {
    int x;
    cin >> x;
    query_range(nums, x);
  }

  return 0;
}
