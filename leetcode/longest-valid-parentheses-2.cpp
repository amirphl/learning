// https://leetcode.com/problems/longest-valid-parentheses/
#include "bits/stdc++.h"
using namespace std;

vector<int> v(30000 + 1);

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
    int c = 0;
    int res = 0;
    for (; i < n; i++) {
      if (s[i] == '(') {
        v[c++] = open;
        continue;
      }
      if (c == 0) {
        return rec(s, i + 1);
      }
      int t = v[--c];
      if (t == open) {
        if (c == 0 || v[c - 1] == open) {
          v[c++] = 1;
          res = max(res, 1);
          continue;
        }
        int next_t = v[--c];
        v[c++] = next_t + 1;
        res = max(res, next_t + 1);
        continue;
      }
      if (c == 0) {
        return max(t, rec(s, i + 1));
      }
      c--;
      int acc = t + 1;
      while (c != 0 && v[c - 1] != open) {
        acc += v[--c];
      }
      v[c++] = acc;
      res = max(res, acc);
    }
    return res;
  }
};
