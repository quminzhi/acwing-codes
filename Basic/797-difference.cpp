#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &diff, int l, int r, int add) {
  diff[l] += add, diff[r + 1] -= add;
}

int main() {
  int n, m;
  cin >> n >> m;

  // the last slot is to prevent overflow of insert routine
  vector<int> diff(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    insert(diff, i, i, x);
  }

  while (m--) {
    int l, r, x;
    // convert to 0-based
    l--, r--;
    cin >> l >> r >> x;
    insert(diff, l, r, x);
  }

  // aggregate
  for (int i = 1; i < n; i++) {
    diff[i] += diff[i - 1];
  }

  for (int i = 0; i < n; i++) {
    cout << diff[i] << " ";
  }
  cout << endl;

  return 0;
}
