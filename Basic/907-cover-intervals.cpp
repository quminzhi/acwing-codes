#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//     o---------------o
//   start            end
//
// 1. sorting by left endpoint
// 2. enumerate all intervals, select the one that covers start point and has
//    the largest rightpoint.
// 3. update start

typedef struct edge {
  int l, r;
} Edge;

int main() {
  int st, ed;
  cin >> st >> ed;

  int n;
  cin >> n;

  vector<Edge> edges;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    edges.push_back({l, r});
  }

  sort(edges.begin(), edges.end(), [](const Edge &lhs, const Edge &rhs) {
    if (lhs.l == rhs.l)
      return lhs.r < rhs.r;
    return lhs.l < rhs.l;
  });

  int res = 0;
  for (int i = 0; i < n; i++) {
    // find the one with largest right endpoint that covers start point
    int j = i, rightmost = -1e9 - 10;
    while (j < n && edges[j].l <= st) {
      rightmost = max(rightmost, edges[j].r);
      j++;
    }

    if (rightmost < st) {
      break;
    }

    res++;
    st = rightmost;

    if (rightmost >= ed) {
      break;
    }

    i = j - 1;
  }

  if (st >= ed) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
