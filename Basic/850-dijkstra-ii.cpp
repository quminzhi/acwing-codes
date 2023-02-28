#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// optimize it with priority_queue

const int inf = 0x3f3f3f3f;

class Node {
public:
  int node, weight;
};

typedef pair<int, int> PII;

int n, m;
vector<vector<Node>> g;

int dijkstra() {
  vector<int> dist(n + 1, inf);
  vector<bool> st(n + 1, false);
  dist[1] = 0;

  priority_queue<PII, vector<PII>, greater<PII>> pq;
  pq.push({dist[1], 1});

  while (pq.size()) {
    auto t = pq.top();
    pq.pop();
    int d = t.first, u = t.second;
    if (st[u])
      continue; // redundancy
    st[u] = true;

    for (auto node : g[u]) {
      if (dist[node.node] > dist[u] + node.weight) {
        dist[node.node] = dist[u] + node.weight;
        pq.push({dist[node.node], node.node});
      }
    }
  }

  return dist[n] == inf ? -1 : dist[n];
}

int main() {
  cin >> n >> m;
  g = vector<vector<Node>>(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back({b, w});
  }

  auto res = dijkstra();
  cout << res << endl;

  return 0;
}
