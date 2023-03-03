#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// f[i][j] means the length of the longest common subsequence of s[1..i] and
// p[1..j]
//
// f[i][j] = f[i - 1][j - 1] if s[i] != p[j]
//         = f[i - 1][j - 1] + 1 if s[i] == p[j]
//         = f[i - 1][j], where s[i] is not in LCS
//         = f[i][j - 1], where p[j] is not in LCS

int main() {
  int n, m;
  cin >> n >> m;

  string s, p;
  cin >> s >> p;
  s = ' ' + s, p = ' ' + p;

  int f[n + 1][m + 1];
  memset(f, 0, sizeof f);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = f[i - 1][j - 1];
      f[i][j] = max(f[i][j], max(f[i - 1][j], f[i][j - 1]));
      if (s[i] == p[j]) {
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
      }
    }
  }

  cout << f[n][m] << endl;

  return 0;
}
