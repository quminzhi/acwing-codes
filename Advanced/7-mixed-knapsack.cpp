#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int f[m + 1];
  memset(f, 0, sizeof f);

  for (int i = 1; i <= n; i++) {
    int vv, ww, ss;
    cin >> vv >> ww >> ss;

    if (ss == 0) {
      // complete knapsack
      for (int j = vv; j <= m; j++) {
        f[j] = max(f[j], f[j - vv] + ww);
      }
    } else {
      if (ss == -1)
        ss = 1;
      // limited knapsack => binary optimization
      vector<int> v, w;
      int k = 1;
      while (ss - k >= 0) {
        v.push_back(vv * k);
        w.push_back(ww * k);
        ss -= k;
        k = k << 1;
      }
      if (ss) {
        v.push_back(vv * ss);
        w.push_back(ww * ss);
      }

      for (int t = 0; t < v.size(); t++) {
        for (int j = m; j >= v[t]; j--) {
          f[j] = max(f[j], f[j - v[t]] + w[t]);
        }
      }
    }
  }

  cout << f[m] << endl;

  return 0;
}
