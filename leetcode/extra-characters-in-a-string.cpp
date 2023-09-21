// https://leetcode.com/problems/extra-characters-in-a-string/
#include "bits/stdc++.h"
using namespace std;

int dp[50];
class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    memset(dp, -1, sizeof(dp));
    return minExtraChar(s, dictionary, 0);
  }
  int minExtraChar(string s, vector<string> &dictionary, const int pos) {
    int n = s.length();
    if (pos == n) {
      return 0;
    }
    if (dp[pos] != -1) {
      return dp[pos];
    }
    int res = n - pos;
    for (auto &c : dictionary) {
      int i = pos;
      int j = 0;
      int m = c.size();
      while (i < n && j < m && s[i] == c[j]) {
        i++;
        j++;
      }
      if (j != m) {
        continue;
      }
      res = min(res, minExtraChar(s, dictionary, i));
    }
    res = min(res, 1 + minExtraChar(s, dictionary, pos + 1));
    return dp[pos] = res;
  }
};
