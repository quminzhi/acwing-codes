#include <iostream>
#include <vector>
using namespace std;

// 1. enumerate on each group.
// 2. choose only one or nothing for each group

typedef struct item {
  int v, w;
} Item;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Item>> groups(n + 1);

  for (int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      int v, w;
      cin >> v >> w;
      groups[i].push_back({v, w});
    }
  }

  vector<vector<int>> f(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j] = max(f[i][j], f[i - 1][j]);
      for (int k = 0; k < groups[i].size(); k++) {
        if (j >= groups[i][k].v)
          f[i][j] = max(f[i][j], f[i - 1][j - groups[i][k].v] + groups[i][k].w);
      }
    }
  }

  cout << f[n][m] << endl;

  return 0;
}
