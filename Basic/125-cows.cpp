#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 *  sort cows by weight and analyze what would happen if we swap any two cows
 *
 *  for ith and i+1th cow,
 *
 *           before           after    (swap)
 *    ith    t - si       t + wi+1 - si
 *  i+1th  t + wi - si+1    t - si+1
 *
 *  where t = w1 + w2 + ... + wi-1
 *
 *  we want to find MAX for before and after respectively.
 *
 *  t + wi - si+1 > t - si+1 (wi > 0)
 *  if t + wi - si+1 > t + wi+1 - si, then wi + si > wi+1 + si+1
 *
 *  ===> if wi + si > wi+1 + si+1, before > after, it's a good choice to swap
 * ith and i+1th cow.
 *
 *  ===> sort by (wi + si) and find max risk
 */

typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  vector<PII> cows;
  for (int i = 0; i < n; i++) {
    int weight, afford;
    cin >> weight >> afford;
    cows.push_back({weight, afford});
  }

  sort(cows.begin(), cows.end(), [](const PII &lhs, const PII &rhs) {
    return lhs.first + lhs.second < rhs.first + rhs.second;
  });

  int res = -INF, sum = 0;

  for (int i = 0; i < n; i++) {
    res = max(res, sum - cows[i].second);
    sum += cows[i].first;
  }

  cout << res << endl;

  return 0;
}
