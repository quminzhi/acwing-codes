#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int id, weight;
};

const int inf = 0x3f3f3f3f;

int n, m;
vector<vector<Node>> g;

bool spfa() {
  vector<int> dist(n + 1, inf);
  vector<int> cnt(n + 1, 0); // the time of node i being updated
  vector<bool> st(n + 1, false);

  dist[1] = 0;
  queue<int> que;

  // some negative loop may be not directedly connected with node 1
  for (int i = 1; i <= n; i++) {
    que.push(i);
    st[i] = true;
  }

  while (que.size()) {
    int cur = que.front();
    que.pop();

    st[cur] = false;

    for (auto node : g[cur]) {
      int u = node.id, d = node.weight;
      if (dist[u] > dist[cur] + d) {
        dist[u] = dist[cur] + d;
        cnt[u]++;

        if (cnt[u] >= n)
          return true;
        if (!st[u]) {
          que.push(u);
          st[u] = true;
        }
      }
    }
  }

  return false;
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
  if (res) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
