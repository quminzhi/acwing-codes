#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string mul(string &a, string &b) {
  // reverse => [lsb, msb]
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  vector<int> c(a.size() + b.size());
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += (a[i] - '0') * (b[j] - '0');
    }
  }

  // solve carries
  string res;
  for (int i = 0, ca = 0; i < c.size() || ca; i++) {
    if (i < c.size())
      ca += c[i];
    res.push_back((ca % 10) + '0');
    ca /= 10;
  }

  // leading 0 in res
  // '>0' ensures the result is not empty for the case of "0"
  int i = res.size() - 1;
  while (i > 0 && res[i] == '0') {
    res.pop_back();
    i--;
  }

  // reverse => [msb, lsb]
  reverse(res.begin(), res.end());

  return res;
}

int main() {
  string a, b;
  cin >> a >> b;

  string res = mul(a, b);
  cout << res << endl;

  return 0;
}
