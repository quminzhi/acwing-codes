#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longest_subsequence(vector<int> &nums) {
  unordered_set<int> seen;
  int res = 0;

  for (int i = 0, j = 0; i < nums.size(); i++) {
    while (seen.count(nums[i])) {
      seen.erase(nums[j++]);
    }
    seen.insert(nums[i]);
    res = max(res, i - j + 1);
  }

  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int res = longest_subsequence(nums);
  cout << res << endl;

  return 0;
}
