#include <iostream>
#include <vector>
using namespace std;

// check if a graph if a bipartite graph by coloring nodes of the graph.
// 1. if node i has not been colored, then color it and try the next node.
// 2. if node i has been colored, check if there is a conflict.

int n, m;
vector<vector<int>> g;
vector<int> color; // 0: not colored, 1: black, 2: red.

bool dfs(int id, int c) {
  color[id] = c;

  for (auto node : g[id]) {
    if (color[node]) {
      if (color[node] == c)
        return false;
    } else {
      if (!dfs(node, 3 - c))
        return false;
    }
  }

  return true;
}

bool isBipartite() {
  color = vector<int>(n + 1, 0);
  // try to start from each node
  for (int i = 1; i <= n; i++) {
    if (!color[i]) {
      if (!dfs(i, 1))
        return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;

  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }

  if (isBipartite()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
