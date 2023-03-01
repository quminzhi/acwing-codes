#include <iostream>
#include <vector>
using namespace std;

// 1. select one node arbitrarily into the tree.
// 2. update min distance of the other nodes from the tree.
// 3. choose the node with min distance and put it in the tree.
// 4. jump to step 2 until all nodes are in the tree or min distance is inf.

const int inf = 0x3f3f3f3f;

int n, m;
vector<vector<int>> g;

int prim() {
  vector<int> dist(n + 1, inf);
  vector<bool> st(n + 1, false);

  dist[1] = 0; // select node 1 for the first time by default
  int sum = 0;

  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++) {
      if (!st[j] && (t == -1 || dist[t] > dist[j])) {
        t = j;
      }
    }

    if (dist[t] == inf)
      return inf;
    if (i)
      sum += dist[t];
    st[t] = true;

    for (int j = 1; j <= n; j++) {
      dist[j] = min(dist[j], g[t][j]);
    }
  }

  return sum;
}

int main() {
  cin >> n >> m;

  g = vector<vector<int>>(n + 1, vector<int>(n + 1, inf));
  for (int i = 0; i <= n; i++) {
    g[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a][b] = g[b][a] = min(g[a][b], w);
  }

  auto res = prim();
  if (res == inf) {
    cout << "impossible" << endl;
  } else {
    cout << res << endl;
  }

  return 0;
}
