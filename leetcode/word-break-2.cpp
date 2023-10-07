#include "bits/stdc++.h"
using namespace std;

short dp[301];
class Solution {
  unordered_set<string> collection;

public:
  bool wordBreak(string &s, vector<string> &wordDict) {
    memset(dp, -1, sizeof(dp));
    collection = unordered_set<string>(wordDict.begin(), wordDict.end());
    return rec(s, 0);
  }
  bool rec(string &s, int pos) {
    int n = s.length();
    if (pos == n) {
      return 1;
    }
    if (dp[pos] != -1) {
      return dp[pos];
    }
    for (int i = pos; i < n; i++) {
      if (collection.find(s.substr(pos, i - pos + 1)) != collection.end() &&
          rec(s, i + 1)) {
        return dp[pos] = 1;
      }
    }
    return dp[pos] = 0;
  }
};
