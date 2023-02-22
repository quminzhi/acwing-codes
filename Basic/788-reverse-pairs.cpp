#include <iostream>
#include <vector>
using namespace std;

long long reverse_pairs(vector<int> &nums, int l, int r) {
  if (l >= r)
    return 0;

  int mid = l + (r - l) / 2;
  int left = reverse_pairs(nums, l, mid);
  int right = reverse_pairs(nums, mid + 1, r);

  long long sum = left + right;

  vector<int> buf;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      buf.push_back(nums[i++]);
    } else {
      sum += mid - i + 1;
      buf.push_back(nums[j++]);
    }
  }

  while (i <= mid) {
    buf.push_back(nums[i++]);
  }
  while (j <= r) {
    buf.push_back(nums[j++]);
  }

  for (int i = 0, j = l; i < buf.size(); i++) {
    nums[j++] = buf[i];
  }

  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  long long res = reverse_pairs(nums, 0, nums.size() - 1);
  cout << res << endl;

  return 0;
}
