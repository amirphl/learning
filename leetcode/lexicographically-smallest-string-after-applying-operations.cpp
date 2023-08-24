// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
#include "bits/stdc++.h"
#include <unordered_set>
using namespace std;

class Solution {
  int a, b;

public:
  string findLexSmallestString(string &s, const int a, const int b) {
    this->a = a;
    this->b = b;
    string ans = s;
    unordered_set<string> visited;
    solve(s, visited, ans);
    return ans;
  }
  void solve(string &s, unordered_set<string> &visited, string &ans) {
    if (s < ans) {
      ans = s;
    }
    visited.insert(s);
    string backup = s;
    int n = s.length();
    for (int i = 1; i < n; i += 2) {
      s[i] = (char)(((s[i] - '0' + a) % 10) + '0');
    }
    if (visited.find(s) == visited.end()) {
      solve(s, visited, ans);
    }
    s = backup;
    rotate(s.begin(), s.begin() + n - b, s.end());
    if (visited.find(s) == visited.end()) {
      solve(s, visited, ans);
    }
  }
};
