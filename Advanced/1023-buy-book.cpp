#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int m;
  cin >> m;

  vector<int> v = {10, 20, 50, 100};

  int f[m + 1];
  memset(f, 0, sizeof f);
  f[0] = 1;

  for (int i = 0; i < v.size(); i++) {
    for (int j = v[i]; j <= m; j++) {
      f[j] += f[j - v[i]];
    }
  }

  cout << f[m] << endl;

  return 0;
}
