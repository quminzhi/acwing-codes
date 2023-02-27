#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

vector<int> topo(vector<vector<int>> &g, vector<int> &id) {
  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (id[i] == 0) {
      que.push(i);
    }
  }

  vector<int> res;
  while (que.size()) {
    auto cur = que.front();
    que.pop();
    res.push_back(cur);
    for (auto node : g[cur]) {
      id[node]--;
      if (id[node] == 0)
        que.push(node);
    }
  }

  return res;
}

int main() {
  cin >> n >> m;
  vector<vector<int>> g(n + 1);

  vector<int> id(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    id[b]++;
  }

  auto res = topo(g, id);
  if (res.size() == n) {
    for (auto num : res)
      cout << num << " ";
    cout << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
