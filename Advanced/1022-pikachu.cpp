#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// limit: the number of balls and the HP of pikachu
// target: 1. as many as elf as possible
//         2. the HP of pikachu left is as high as possible
//
// f[i][j1][j2] = max(f[i - 1][j1][j2], f[i - 1][j1 - v1[i]][j2 - v2[i]] + w[i])

int main() {
  int m, hp, n;
  cin >> m >> hp >> n;

  vector<int> v1(n + 1), v2(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v1[i] >> v2[i];
  }

  int f[m + 1][hp + 1];
  memset(f, 0, sizeof f);
  for (int i = 1; i <= n; i++) {
    for (int j1 = m; j1 >= v1[i]; j1--) {
      // consume at most hp - 1
      for (int j2 = hp - 1; j2 >= v2[i]; j2--) {
        f[j1][j2] = max(f[j1][j2], f[j1 - v1[i]][j2 - v2[i]] + 1);
      }
    }
  }

  // the HP left must be greater than 0
  int j2 = hp - 1;
  while (j2 - 1 >= 0 && f[m][j2 - 1] == f[m][hp - 1])
    j2--;

  cout << f[m][j2] << " " << hp - j2 << endl;

  return 0;
}
