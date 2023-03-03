#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 1. sort by right endpoint
// 2. if cur.left > right most selected point
//      cur.right is selected and update right most selected point
// 3. if cur.left <= right most selected point
//      which means cur interval is covered by selected points.

typedef struct edge {
  int l, r;
} Edge;

int main() {
  int n;
  cin >> n;

  vector<Edge> edges;

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    edges.push_back({l, r});
  }

  sort(edges.begin(), edges.end(), [](const Edge &lhs, const Edge &rhs) {
    if (lhs.r == rhs.r)
      return lhs.l < rhs.l;
    return lhs.r < rhs.r;
  });

  int res = 0, rightmost = -1e9 - 10;
  for (auto &edge : edges) {
    int l = edge.l, r = edge.r;
    if (l > rightmost) {
      res++;
      rightmost = r;
    } else {
      // nothing to do
    }
  }

  cout << res << endl;

  return 0;
}
