#include <iostream>
#include <vector>
using namespace std;

// check if a is the subsequence of b
bool is_subsequence(vector<int> &a, vector<int> &b) {
  int i = 0, j = 0;
  for (; i < a.size() && j < b.size(); j++) {
    if (a[i] == b[j])
      i++;
  }
  return i >= a.size();
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  if (is_subsequence(a, b)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
