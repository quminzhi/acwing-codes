#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string add(string &a, string &b) {
  // reverse
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  // add
  string res;
  for (int i = 0, j = 0, c = 0; c || i < a.size() || j < b.size();) {
    if (i < a.size())
      c += a[i++] - '0';
    if (j < b.size())
      c += b[j++] - '0';
    res.push_back(c % 10 + '0');
    c /= 10;
  }

  // reverse to [msb, lsb]
  reverse(res.begin(), res.end());

  return res;
}

int main() {
  string a, b;
  cin >> a >> b;

  string res = add(a, b);
  cout << res << endl;

  return 0;
}
