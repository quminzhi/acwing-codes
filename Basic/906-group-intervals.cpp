#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// same as leetcode meeting room ii
//
// 1. sorting by left endpoint
// 2. if min of right endpoint in each group is greater than cur.left,
//      create a new group
//    else
//      append cur to the group with min right endpoint

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
    if (lhs.l == rhs.l)
      return lhs.r < rhs.r;
    return lhs.l < rhs.l;
  });

  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto &edge : edges) {
    int l = edge.l, r = edge.r;
    if (pq.size()) {
      int min = pq.top();
      if (l > min) {
        pq.pop();
        pq.push(r);
      } else {
        pq.push(r);
      }
    } else {
      pq.push(r);
    }
  }

  cout << pq.size() << endl;

  return 0;
}
