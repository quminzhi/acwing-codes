#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &nums, int l, int r) {
  if (l >= r)
    return;

  int mid = l + (r - l) / 2;
  merge_sort(nums, l, mid);
  merge_sort(nums, mid + 1, r);

  vector<int> buf;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      buf.push_back(nums[i++]);
    } else {
      buf.push_back(nums[j++]);
    }
  }

  while (i <= mid) {
    buf.push_back(nums[i++]);
  }
  while (j <= r) {
    buf.push_back(nums[j++]);
  }

  // merge
  for (int i = 0, j = l; i < r - l + 1; i++) {
    nums[j++] = buf[i];
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  merge_sort(nums, 0, nums.size() - 1);

  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
