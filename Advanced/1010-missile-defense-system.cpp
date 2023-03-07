#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// greedy: similar to meeting room, choose the best system for ith missile
//
// for ith missile:
//  - use existed systems to intercept, choose the one just above the height of
//  ith missile
//  - if no system available, create a new system for ith missile

const int N = 10000;

int main() {
  int q[N];
  int n = 0;
  while (cin >> q[n])
    n++;

  int res = 0;
  int f[n];
  memset(f, 0, sizeof f);
  for (int i = 0; i < n; i++) {
    f[i] = 1;
    for (int j = 0; j < i; j++) {
      if (q[j] >= q[i]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
    res = max(res, f[i]);
  }

  cout << res << endl;

  // g is monotonically decreasing
  vector<int> g;
  for (int i = 0; i < n; i++) {
    // find the first one greater than or equal to q[i]
    int k = 0;
    while (k < g.size() && g[k] < q[i])
      k++;
    if (k < g.size()) {
      g[k] = q[i];
    } else {
      g.push_back(q[i]);
    }
  }

  cout << g.size() << endl;

  return 0;
}
