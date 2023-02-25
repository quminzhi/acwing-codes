#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// bfs: it would be the shortest path when i first step on to that cell.
int m, n;
vector<vector<int>> g;
vector<vector<int>> dist;

const int inf = 0x3f3f3f3f;

typedef pair<int, int> PII;

int main() {
  cin >> m >> n;
  g = vector<vector<int>>(m, vector<int>(n));
  dist = vector<vector<int>>(m, vector<int>(n, inf));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  dist[0][0] = g[0][0] == 1 ? inf : 0;
  queue<PII> que;
  que.push({0, 0});

  const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

  while (que.size()) {
    auto cur = que.front();
    que.pop();
    int x = cur.first, y = cur.second;
    if (dist[x][y] == inf)
      continue;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == 0 &&
          dist[nx][ny] == inf) {
        dist[nx][ny] = dist[x][y] + 1;
        que.push({nx, ny});
      }
    }
  }

  cout << dist[m - 1][n - 1] << endl;

  return 0;
}
