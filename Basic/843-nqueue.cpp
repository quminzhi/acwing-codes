#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> g;
vector<bool> col, diag, anti;

void dfs(int r) {
  if (r >= n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << g[i][j];
      }
      cout << endl;
    }
    cout << endl;
    return;
  }

  // enumerate columns on rth row
  // diag: y = x + k, k = y - x (offset + n)
  // anti: y = -x + k, k = y + x (no need to offset)
  for (int c = 0; c < n; c++) {
    if (!col[c] && !anti[r + c] && !diag[c - r + n]) {
      col[c] = anti[r + c] = diag[c - r + n] = true;
      g[r][c] = 'Q';
      dfs(r + 1);
      g[r][c] = '.';
      col[c] = anti[r + c] = diag[c - r + n] = false;
    }
  }
}

int main() {
  cin >> n;

  g = vector<vector<char>>(n, vector<char>(n, '.'));
  col = vector<bool>(n, false);
  diag = vector<bool>(n + n - 1, false);
  anti = vector<bool>(n + n - 1, false);
  dfs(0);

  return 0;
}
