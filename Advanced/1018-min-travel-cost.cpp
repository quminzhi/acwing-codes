#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int f[n + 1][n + 1];
  memset(f, 0x3f, sizeof f);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> f[i][j];
    }
  }

  f[0][1] = 0; // or f[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] += min(f[i - 1][j], f[i][j - 1]);
    }
  }

  cout << f[n][n] << endl;

  return 0;
}
