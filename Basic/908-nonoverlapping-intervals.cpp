#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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
    if (l <= rightmost) {
      // cur cannot be chosen
    } else {
      res++;
      rightmost = r;
    }
  }

  cout << res << endl;

  return 0;
}
