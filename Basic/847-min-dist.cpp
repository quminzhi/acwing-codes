#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;
vector<vector<int>> g;

int minDist(int u) {
  vector<int> dist(n + 1, inf);
  dist[u] = 0;

  queue<int> que;
  que.push(u);

  while (que.size()) {
    auto cur = que.front();
    que.pop();

    for (auto node : g[cur]) {
      if (dist[node] == inf) {
        dist[node] = dist[cur] + 1;
        que.push(node);
      }
    }
  }

  return dist[n] == inf ? -1 : dist[n];
}

int main() {
  cin >> n >> m;

  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  auto res = minDist(1);
  cout << res << endl;

  return 0;
}
