#include <iostream>
#include <vector>
using namespace std;

int pop_count(int x) {
  int cnt = 0;
  for (; x; x -= x & -x) {
    cnt++;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;
    cout << pop_count(x) << " ";
  }
  cout << endl;

  return 0;
}
