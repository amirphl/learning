// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  bool splitString(string &s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
      if (rec(s, i + 1, s.substr(0, i + 1))) {
        return 1;
      }
    }
    return 0;
  }

  bool rec(string &s, const int pos, const string target) {
    int n = s.length();
    if (pos == n) {
      return 1;
    }
    for (int i = pos; i < n; i++) {
      const string x = s.substr(pos, i - pos + 1);
      const string x_plus_one = plus(x);
      if (less(x_plus_one, target)) {
        continue;
      } else if (equals(x_plus_one, target)) {
        if (rec(s, i + 1, x)) {
          return 1;
        }
      } else {
        break;
      }
    }
    return 0;
  }

  string plus(string s) {
    int n = s.length();
    int c = 1;
    for (int i = n - 1; i >= 0 && c; i--) {
      c += s[i] - '0';
      s[i] = '0' + (c % 10);
      c /= 10;
    }
    return (c ? string(1, '0' + c) : "") + s;
  }

  bool less(const string &s1, const string &s2) {
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    for (; i < n && s1[i] == '0'; i++)
      ;
    for (; j < m && s2[j] == '0'; j++)
      ;
    if (n - i < m - j) {
      return 1;
    }
    if (n - i > m - j) {
      return 0;
    }
    return s1.substr(i, n - i) < s2.substr(j, m - j);
  }

  bool equals(const string &s1, const string &s2) {
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    for (; i < n && s1[i] == '0'; i++)
      ;
    for (; j < m && s2[j] == '0'; j++)
      ;
    for (; i < n && j < m && s1[i] == s2[j]; i++, j++)
      ;
    return i == n && j == m;
  }
};
