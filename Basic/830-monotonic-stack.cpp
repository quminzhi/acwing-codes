#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> res;
  stack<int> stk;
  for (auto num : nums) {
    while (stk.size() && stk.top() >= num)
      stk.pop();
    if (stk.size())
      res.push_back(stk.top());
    else
      res.push_back(-1);
    stk.push(num);
  }

  for (auto num : res) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
