#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

int main() {
  int n;
  cin >> n;

  vector<PII> cities;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cities.push_back({a, b});
  }

  sort(cities.begin(), cities.end(), [](const PII &lhs, const PII &rhs) {
    if (lhs.first == rhs.first)
      return lhs.second < rhs.second;
    return lhs.first < rhs.first;
  });

  int res = 0;
  int f[n];
  memset(f, 0, sizeof f);
  for (int i = 0; i < n; i++) {
    f[i] = 1;
    for (int j = 0; j < i; j++) {
      if (cities[j].second < cities[i].second) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
    res = max(res, f[i]);
  }

  cout << res << endl;

  return 0;
}
