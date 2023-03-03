#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// f[i][j] means the min distance converting s to p with following operations:
//  - delete a char from s
//  - insert a char into s
//  - modify a char in s to another char
//
// f[i][j] = f[i - 1][j - 1] + 1, modify
//         = f[i - 1][j] + 1, delete
//         = f[i][j - 1] + 1, insert
//         = f[i - 1][j - 1], if s[i] == p[j]

int main() {
  int n, m;
  string s, p;
  cin >> n >> s >> m >> p;

  s = ' ' + s, p = ' ' + p;

  int f[n + 1][m + 1];
  memset(f, 0x3f, sizeof f);
  for (int i = 0; i <= n; i++)
    f[i][0] = i;
  for (int j = 0; j <= m; j++)
    f[0][j] = j;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
      f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
      if (s[i] == p[j]) {
        f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      }
    }
  }

  cout << f[n][m] << endl;

  return 0;
}
