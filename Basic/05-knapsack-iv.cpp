#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1), w(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> s[i];
  }

  vector<int> nv, nw;
  // binary conversion
  for (int i = 1; i <= n; i++) {
    int x = s[i], p = 1;
    while (x >= p) {
      nv.push_back(p * v[i]);
      nw.push_back(p * w[i]);
      x -= p;
      p <<= 1;
    }

    if (x) {
      nv.push_back(x * v[i]);
      nw.push_back(x * w[i]);
    }
  }

  vector<int> f(m + 1);
  // nv and nw is 0-based
  for (int i = 0; i < nv.size(); i++) {
    for (int j = m; j >= nv[i]; j--) {
      f[j] = max(f[j], f[j - nv[i]] + nw[i]);
    }
  }

  cout << f[m] << endl;

  return 0;
}
