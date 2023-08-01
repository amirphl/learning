// https://leetcode.com/problems/score-of-parentheses/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int scoreOfParentheses(string &in) {
    stack<int> s;

    for (auto &ch : in) {
      if (ch == '(') {
        s.push(-1);
      } else {
        if (s.top() == -1) {
          s.pop();
          if (s.empty() || s.top() == -1) {
            s.push(1);
          } else {
            int sum = 0;
            while (!s.empty() && s.top() != -1) {
              sum += s.top();
              s.pop();
            }
            s.push(sum + 1);
          }
        } else {
          int sum = 0;
          while (s.top() != -1) {
            sum += s.top();
            s.pop();
          }
          s.pop();
          s.push(sum * 2);
        }
      }
      // print(s);
    }

    int res = 0;
    while (!s.empty()) {
      res += s.top();
      s.pop();
    }
    return res;
  }

  void print(stack<int> s) {
    while (s.size() > 0) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << "\n";
  }
};
