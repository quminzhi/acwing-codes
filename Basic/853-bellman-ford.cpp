#include <iostream>
#include <vector>
using namespace std;

// update each edge if possible for every loop
// take care of chaining update and inf update inf

const int inf = 0x3f3f3f3f;

class Edge {
public:
  int l, r, weight;
};

int n, m, k;
vector<Edge> edges;

int bellman() {
  vector<int> dist(n + 1, inf);
  dist[1] = 0;

  for (int c = 0; c < k; c++) {
    auto bk = dist;
    for (auto edge : edges) {
      int l = edge.l, r = edge.r, w = edge.weight;
      dist[r] = min(dist[r], bk[l] + w);
    }
  }

  return dist[n];
}

int main() {
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back({a, b, w});
  }

  auto res = bellman();
  if (res >= inf >> 1) {
    cout << "impossible" << endl;
  } else {
    cout << res << endl;
  }

  return 0;
}
