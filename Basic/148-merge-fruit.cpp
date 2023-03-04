#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto num : nums)
    pq.push(num);

  int sum = 0;
  while (pq.size() > 1) {
    auto b = pq.top();
    pq.pop();
    auto a = pq.top();
    pq.pop();
    sum += a + b;
    pq.push(a + b);
  }

  cout << sum << endl;

  return 0;
}
