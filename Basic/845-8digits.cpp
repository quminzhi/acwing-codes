#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> dist;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

// treat each matrix as a state
int bfs(string &start) {
  string end = "12345678x";
  dist[start] = 0;

  queue<string> que;
  que.push(start);

  while (que.size()) {
    auto cur = que.front();
    que.pop();

    int idx = cur.find('x');
    int x = idx / 3, y = idx % 3;
    for (int i = 0; i < 4; i++) {
      auto state = cur;
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
        swap(state[idx], state[nx * 3 + ny]);
        if (dist.find(state) == dist.end()) {
          dist[state] = dist[cur] + 1;
          que.push(state);
        }
      }
    }
  }

  return dist.count(end) ? dist[end] : -1;
}

int main() {
  string s;
  for (int i = 0; i < 9; i++) {
    char ch;
    cin >> ch;
    s += ch;
  }

  int res = bfs(s);
  cout << res << endl;

  return 0;
}
