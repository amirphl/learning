// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // TLE: Testcases passed, but took too long.
  vector<int> findSubstring(string &s, vector<string> &words) {
    const int n = s.length();
    const int w = words.size();
    const int h = words[0].size();
    if (n < w * h) {
      return {};
    }
    unordered_map<string, int> m;
    for (auto &word : words) {
      m[word]++;
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (rec(s, m, i, w, h)) {
        res.push_back(i);
      }
    }
    return res;
  }

  bool rec(string &s, unordered_map<string, int> &m, const int pos, const int w,
           const int h) {
    if (w == 0) {
      return 1;
    }
    const int n = s.length();
    if (n - pos < w * h) {
      return 0;
    }
    string prefix = s.substr(pos, h);
    if (m.find(prefix) != m.end() && m[prefix] > 0) {
      m[prefix]--;
      if (rec(s, m, pos + h, w - 1, h)) {
        m[prefix]++;
        return 1;
      }
      m[prefix]++;
    }
    return 0;
  }
};
