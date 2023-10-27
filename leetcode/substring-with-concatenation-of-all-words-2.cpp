// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // TLE: Time Limit Exceeded
  vector<int> findSubstring(string &s, vector<string> &words) {
    const int n = s.length();
    const int w = words.size();
    unordered_map<string, int> m;
    for (auto &word : words) {
      m[word]++;
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (rec(s, m, i, w)) {
        res.push_back(i);
      }
    }
    return res;
  }

  bool rec(string &s, unordered_map<string, int> &m, const int pos,
           const int w) {
    if (w == 0) {
      return 1;
    }
    const int n = s.length();
    for (int i = pos; i < n; i++) {
      string prefix = s.substr(pos, i - pos + 1);
      if (m.find(prefix) != m.end() && m[prefix] > 0) {
        m[prefix]--;
        if (rec(s, m, i + 1, w - 1)) {
          m[prefix]++;
          return 1;
        }
        m[prefix]++;
      }
    }
    return 0;
  }
};
