// https://leetcode.com/problems/longest-word-in-dictionary/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  string longestWord(vector<string> &words) {
    unordered_set<string> hashset(words.begin(), words.end());
    int n = words.size();
    int len = 0;
    string res;
    for (auto &w : words) {
      int m = w.size();
      int j = 1;
      for (; j <= m && hashset.find(w.substr(0, j)) != hashset.end(); j++)
        ;
      if (j == m + 1 && (len < m || (len == m && w <= res))) {
        res = w;
        len = m;
      }
    }
    return res;
  }
};
