#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &arr, int l, int r) {
  if (l >= r)
    return;

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

  quick_sort(arr, l, j);
  quick_sort(arr, j + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  quick_sort(nums, 0, nums.size() - 1);

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
