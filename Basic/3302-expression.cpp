#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

stack<int> nums;
stack<char> opts;

unordered_map<char, int> pred = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() {
  int b = nums.top();
  nums.pop();
  int a = nums.top();
  nums.pop();
  char opt = opts.top();
  opts.pop();

  switch (opt) {
  case '+':
    nums.push(a + b);
    break;
  case '-':
    nums.push(a - b);
    break;
  case '*':
    nums.push(a * b);
    break;
  case '/':
    nums.push(a / b);
    break;
  default:
    perror("Failed to parse operands.");
  }
}

int cal(string &s) {
  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (ch == ' ')
      continue;
    if (isdigit(ch)) {
      int j = i;
      while (j < s.size() && isdigit(s[j]))
        j++;
      auto x = stoi(s.substr(i, j - i));
      i = j - 1;
      nums.push(x);
    } else if (ch == '(') {
      opts.push(ch);
    } else if (ch == ')') {
      while (opts.size() && opts.top() != '(') {
        eval();
      }
      if (opts.size())
        opts.pop(); // may be empty, pop '('
    } else {
      // operations
      while (opts.size() && pred[opts.top()] >= pred[ch]) {
        eval();
      }
      opts.push(ch);
    }
  }

  while (opts.size())
    eval();
  return nums.top();
}

int main() {
  string expr;
  cin >> expr;

  auto res = cal(expr);
  cout << res << endl;

  return 0;
}
