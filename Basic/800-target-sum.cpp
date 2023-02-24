#include <iostream>
#include <vector>
using namespace std;

void find_target(vector<int> &a, vector<int> &b, int target) {
  for (int i = 0, j = b.size() - 1; i < a.size() && j >= 0;) {
    int sum = a[i] + b[j];
    if (sum == target) {
      cout << i << " " << j << endl;
      return;
    } else {
      if (sum > target)
        j--;
      else
        i++;
    }
  }
  cout << -1 << " " << -1 << endl;
}

int main() {
  int n, m, target;
  cin >> n >> m >> target;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  find_target(a, b, target);

  return 0;
}
