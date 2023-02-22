#include <iostream>
#include <vector>
using namespace std;

double cube_root(double x) {
  double l = -100, r = 100;
  while (r - l >= 1e-8) {
    double mid = (l + r) / 2;
    if (mid * mid * mid >= x) {
      r = mid;
    } else {
      l = mid;
    }
  }

  return l;
}

int main() {
  double n;
  cin >> n;

  double res = cube_root(n);
  printf("%.6f\n", res);

  return 0;
}
