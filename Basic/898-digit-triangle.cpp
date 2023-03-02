#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> g(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> g[i][j];
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      g[i][j] += max(g[i + 1][j], g[i + 1][j + 1]);
    }
  }

  cout << g[0][0] << endl;

  return 0;
}
