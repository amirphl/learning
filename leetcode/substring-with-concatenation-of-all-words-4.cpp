// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string &s, vector<string> &words) {
    const int n = s.length();
    const int w = words.size();
    const int h = words[0].size();
    unordered_map<string, int> m;
    // unordered_map<string, int> v;
    for (auto &word : words) {
      m[word]++;
    }
    vector<int> res;
    for (int i = 0; i <= n - w * h; i++) {
      unordered_map<string, int> v;
      int cnt = 0;
      int k = i + w * h;
      for (int j = i; j < k && cnt < w; j += h) {
        string sub = s.substr(j, h);
        if (m.find(sub) != m.end() && v[sub] < m[sub]) {
          v[sub]++;
          cnt++;
        } else {
          break;
        }
      }
      if (cnt == w) {
        res.push_back(i);
      }
      // v.clear();
    }
    return res;
  }
};
