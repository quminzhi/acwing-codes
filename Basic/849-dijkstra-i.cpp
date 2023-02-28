#include <iostream>
#include <vector>
using namespace std;

// 1. select the node with minimum distance from candidate group
// 2. remove it from the candidate group
// 3. update nodes in the candidate group

const int inf = 0x3f3f3f3f;

int n, m;
vector<vector<int>> g;

int dijkstra() {
  vector<int> dist(n + 1, inf);
  vector<int> st(n + 1, false);
  dist[1] = 0;

  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++) {
      if (!st[j] && (t == -1 || dist[j] < dist[t])) {
        t = j;
      }
    }

    if (dist[t] == inf)
      break;
    st[t] = true;

    for (int j = 1; j <= n; j++) {
      if (g[t][j] != inf) {
        dist[j] = min(dist[j], dist[t] + g[t][j]);
      }
    }
  }

  return dist[n] == inf ? -1 : dist[n];
}

int main() {
  cin >> n >> m;
  g = vector<vector<int>>(n + 1, vector<int>(n + 1, inf));

  for (int i = 1; i <= n; i++)
    g[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a][b] = min(g[a][b], w);
  }

  auto res = dijkstra();
  cout << res << endl;

  return 0;
}
