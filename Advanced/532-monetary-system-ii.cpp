#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// find the largest independent set
//
// if f[coins[i]] == 0, then coins[i] is in the set, otherwise coins[i] can be
// represented as linear combination of a[1] to a[i - 1].
//
// sort coins firstly

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    int coins[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> coins[i];
    }

    // [open, close)
    sort(coins + 1, coins + n + 1);

    int m = coins[n];
    int f[m + 1];
    memset(f, 0, sizeof f);
    f[0] = 1;

    int res = 0;

    for (int i = 1; i <= n; i++) {
      if (f[coins[i]] == 0)
        res++;
      for (int j = coins[i]; j <= m; j++) {
        f[j] += f[j - coins[i]];
      }
    }

    cout << res << endl;
  }

  return 0;
}
