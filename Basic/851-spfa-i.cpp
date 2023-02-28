#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// an algorithm derived from bellman-ford algorithm, reducing meaningless
// updates by caching updated node in a queue.

class Node {
public:
  int id, weight;
};

int n, m;
vector<vector<Node>> g;

const int inf = 0x3f3f3f3f;

int spfa() {
  vector<int> dist(n + 1, inf);
  vector<bool> st(n + 1, false); // if node i is in the queue
  dist[1] = 0;

  queue<int> que;
  que.push(1);
  st[1] = true;

  while (que.size()) {
    auto cur = que.front();
    que.pop();

    st[cur] = false;

    for (auto node : g[cur]) {
      int u = node.id, w = node.weight;
      if (dist[u] > dist[cur] + w) {
        dist[u] = dist[cur] + w;
        if (!st[u]) {
          que.push(u);
          st[u] = true;
        }
      }
    }
  }

  return dist[n];
}

int main() {
  cin >> n >> m;
  g.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back({b, w});
  }

  auto res = spfa();
  if (res == inf) {
    cout << "impossible" << endl;
  } else {
    cout << res << endl;
  }

  return 0;
}
