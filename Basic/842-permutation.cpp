#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> res;
vector<int> path;
vector<bool> st;

void dfs(int u) {
  if (u >= n) {
    res.push_back(path);
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!st[i]) {
      path.push_back(i);
      st[i] = true;
      dfs(u + 1);
      path.pop_back();
      st[i] = false;
    }
  }
}

int main() {
  cin >> n;
  st.resize(n + 1, false);
  dfs(0);

  for (auto sol : res) {
    for (auto num : sol) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
