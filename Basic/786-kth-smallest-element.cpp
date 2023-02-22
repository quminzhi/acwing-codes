#include <iostream>
#include <vector>
using namespace std;

int quick_select(vector<int> &arr, int l, int r, int k) {
  if (l >= r)
    return arr[l];

  int i = l - 1, j = r + 1, mid = l + (r - l) / 2, x = arr[mid];
  while (i < j) {
    do
      i++;
    while (arr[i] < x);
    do
      j--;
    while (arr[j] > x);
    if (i < j)
      swap(arr[i], arr[j]);
  }

  int lsz = j - l + 1;
  if (k <= lsz)
    return quick_select(arr, l, j, k);
  else
    return quick_select(arr, j + 1, r, k - lsz);
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  auto res = quick_select(nums, 0, nums.size() - 1, k);
  cout << res << endl;

  return 0;
}
