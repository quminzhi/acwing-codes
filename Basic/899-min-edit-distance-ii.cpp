#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int min_edit_dist(string s, string p) {
  int n = s.size(), m = p.size();
  s = ' ' + s, p = ' ' + p;

  int f[n + 1][m + 1];
  memset(f, 0x3f, sizeof f);

  for (int i = 0; i <= n; i++)
    f[i][0] = i;
  for (int j = 0; j <= m; j++)
    f[0][j] = j;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = f[i - 1][j - 1] + 1;
      f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
      if (s[i] == p[j]) {
        f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      }
    }
  }

  return f[n][m];
}

int main() {
  int n, T;
  cin >> n >> T;

  vector<string> lists;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    lists.push_back(s);
  }

  while (T--) {
    string s;
    int limit;
    cin >> s >> limit;

    int cnt = 0;
    for (auto &p : lists) {
      if (min_edit_dist(s, p) <= limit) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
