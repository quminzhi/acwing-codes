#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  // find min in a sliding window
  // an ascending queue
  deque<int> dq;
  vector<int> res_min;
  for (int i = 0; i < nums.size(); i++) {
    // filter from end
    while (dq.size() && nums[i] <= nums[dq.back()])
      dq.pop_back();
    // filter from the beginning: out of window
    while (dq.size() && dq.front() < i - k + 1)
      dq.pop_front();
    // add current one to the candidates
    dq.push_back(i);

    if (i - k + 1 >= 0) {
      res_min.push_back(nums[dq.front()]);
    }
  }

  dq.clear();
  vector<int> res_max;
  for (int i = 0; i < nums.size(); i++) {
    while (dq.size() && nums[i] >= nums[dq.back()])
      dq.pop_back();
    while (dq.size() && dq.front() < i - k + 1)
      dq.pop_front();
    dq.push_back(i);

    if (i - k + 1 >= 0) {
      res_max.push_back(nums[dq.front()]);
    }
  }

  for (auto num : res_min)
    cout << num << " ";
  cout << endl;
  for (auto num : res_max)
    cout << num << " ";
  cout << endl;

  return 0;
}
