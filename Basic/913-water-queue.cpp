#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 *  Say we have only one faucet and n people waiting for water,
 *
 *  t1, t2, t3, ..., tn-1, tn
 *
 *  sum = t1 * (n - 1) + t2 * (n - 2) + ... + tn-1 * 1
 *
 *  Intuitively, sum become minimum when t is sorted in ascending order.
 */

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  long long sum = 0;
  for (int i = 0, k = n - 1; i < n - 1; i++, k--) {
    sum += nums[i] * k;
  }

  cout << sum << endl;

  return 0;
}
