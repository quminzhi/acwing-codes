#include <iostream>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, res;
vector<vector<int>> g;

// return: the sum of weight of the subtree rooted with u
int dfs(int u, int parent) {
  int sum = 0;
  int maxArea = 0;
  for (auto child : g[u]) {
    if (child != parent) {
      int t = dfs(child, u);
      maxArea = max(maxArea, t);
      sum += t;
    }
  }
  sum += 1;                        // current node;
  maxArea = max(maxArea, n - sum); // upper part
  res = min(res, maxArea);

  return sum;
}

int main() {
  cin >> n;
  g.resize(n + 1);

  // for a tree: n nodes has n - 1 edges
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }

  res = inf;
  dfs(1, -1);
  cout << res << endl;

  return 0;
}
