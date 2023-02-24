#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct interval {
  int l, r;
} Interval;

int main() {
  int n;
  cin >> n;

  vector<Interval> intervals;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    intervals.push_back({l, r});
  }

  sort(intervals.begin(), intervals.end(), [](Interval &lhs, Interval &rhs) {
    if (lhs.l == rhs.l) {
      return lhs.r < rhs.r;
    }
    return lhs.l < rhs.l;
  });

  int cnt = 0, rightmost = -0x3f3f3f3f;
  for (auto &interval : intervals) {
    if (interval.l <= rightmost) {
      rightmost = max(rightmost, interval.r);
    } else {
      cnt++;
      rightmost = interval.r;
    }
  }

  cout << cnt << endl;

  return 0;
}
