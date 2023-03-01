#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// construct tree in a greedy way:
// 1. sort all edges
// 2. choose the one edge with min distance and two nodes at the end of the edge
//    are not in the same cluster. (union set)

class UnionSet {
public:
  vector<int> p;
  int sz;

  UnionSet(int n) {
    sz = n;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
      p[i] = i;
  }

  int find(int x) {
    if (p[x] != x) {
      p[x] = find(p[x]);
    }
    return p[x];
  }

  void join(int x, int y) {
    if (find(x) != find(y)) {
      p[find(x)] = find(y);
      sz--;
    }
  }

  int size() { return sz; }
};

class Edge {
public:
  int l, r, w;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back({a, b, w});
  }

  sort(edges.begin(), edges.end(),
       [](const Edge &lhs, const Edge &rhs) { return lhs.w < rhs.w; });

  int sum = 0;
  UnionSet uset(n);
  for (auto &edge : edges) {
    int l = edge.l, r = edge.r, w = edge.w;
    if (uset.find(l) != uset.find(r)) {
      uset.join(l, r);
      sum += w;
    }
  }

  if (uset.size() == 1) {
    cout << sum << endl;
  } else {
    cout << "impossible" << endl;
  }

  return 0;
}
