// https://leetcode.com/problems/longest-valid-parentheses/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int longestValidParentheses(string &s) { return 2 * rec(s, 0); }
  int rec(const string &s, const int pos) {
    const int n = s.length();
    int i = pos;
    for (; i < n && s[i] == ')'; i++)
      ;
    if (i == n) {
      return 0;
    }
    const int open = -2;
    stack<int> p;
    int res = 0;
    for (; i < n; i++) {
      if (s[i] == '(') {
        p.push(open);
        continue;
      }
      if (p.empty()) {
        return rec(s, i + 1);
      }
      int t = p.top();
      p.pop();
      if (t == open) {
        if (p.empty() || p.top() == open) {
          p.push(1);
          res = max(res, 1);
          continue;
        }
        int next_t = p.top();
        p.pop();
        // if (!p.empty() && p.top() != open) {
        //   cout << "---> " << p.top() << "   " << i << endl;
        // }
        p.push(next_t + 1);
        res = max(res, next_t + 1);
        continue;
      }
      if (p.empty()) {
        return max(t, rec(s, i + 1));
      }
      p.pop();
      int acc = t + 1;
      while (!p.empty() && p.top() != open) {
        acc += p.top();
        p.pop();
      }
      p.push(acc);
      res = max(res, acc);
    }
    return res;
  }
};
