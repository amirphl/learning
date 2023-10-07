#include "bits/stdc++.h"
using namespace std;

class Solution {
  unordered_set<string> collection;

public:
  // TLE
  bool wordBreak(string &s, vector<string> &wordDict) {
    collection = unordered_set<string>(wordDict.begin(), wordDict.end());
    return rec(s, 0);
  }
  bool rec(string &s, int pos) {
    int n = s.length();
    if (pos == n) {
      return 1;
    }
    for (int i = pos; i < n; i++) {
      if (collection.find(s.substr(pos, i - pos + 1)) != collection.end() &&
          rec(s, i + 1)) {
        return 1;
      }
    }
    return 0;
  }
};
