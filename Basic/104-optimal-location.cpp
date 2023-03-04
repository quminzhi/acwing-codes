#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 *  absolute value inequality: assumed there are only two shops
 *
 *  ----o------------o------
 *      a            b
 *
 *  |x - a| + |x - b| >= |a - b| and when x in [a, b], we get the min value
 *
 *  ===> split all shops into pairs and we can conclude that 2
 *
 *  1. sort the shops
 *  2. if number of shops is odd, choose the middle one
 *     if number of shops is even, choose any point in [middle_l, middle_r]
 */

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  int res = 0;
  for (int l = 0, r = n - 1; l < r; l++, r--) {
    res += nums[r] - nums[l];
  }

  cout << res << endl;

  return 0;
}
