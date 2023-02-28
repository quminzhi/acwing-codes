#include <iostream>
#include <vector>
using namespace std;

// dynamic programming
// prevent inf from updating inf

const int inf = 0x3f3f3f3f;

int n, m, T;
vector<vector<int>> d;

void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m >> T;
  d = vector<vector<int>>(n + 1, vector<int>(n + 1, inf));
  for (int i = 0; i <= n; i++)
    d[i][i] = 0;

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    d[a][b] = min(d[a][b], w);
  }

  floyd();

  while (T--) {
    int a, b;
    cin >> a >> b;
    if (d[a][b] >= inf >> 1)
      cout << "impossible" << endl;
    else
      cout << d[a][b] << endl;
  }

  return 0;
}
