// https://leetcode.com/problems/interleaving-string/
#include "bits/stdc++.h"
using namespace std;

short dp[101][101][2];
class Solution {
public:
  bool isInterleave(string &s1, string &s2, string &s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return 0;
    }
    memset(dp, -1, sizeof(dp));
    return rec(s1, s2, s3, 0, 0, 0, 0) || rec(s1, s2, s3, 0, 0, 0, 1);
  }
  bool rec(string &s1, string &s2, string &s3, const int i, const int j,
           const int k, const bool flag) {
    int n = s1.length();
    int m = s2.length();
    int p = s3.length();
    if (i == n && j == m) {
      return dp[i][j][flag] = 1;
    }
    if (dp[i][j][flag] != -1) {
      return dp[i][j][flag];
    }
    dp[i][j][flag] = 0;
    if (flag) {
      for (int x = 0; i + x < n && k + x < p && s1[i + x] == s3[k + x]; x++) {
        if (rec(s1, s2, s3, i + x + 1, j, k + x + 1, 0)) {
          return dp[i][j][flag] = 1;
        }
      }
    } else {
      for (int x = 0; j + x < m && k + x < p && s2[j + x] == s3[k + x]; x++) {
        if (rec(s1, s2, s3, i, j + x + 1, k + x + 1, 1)) {
          return dp[i][j][flag] = 1;
        }
      }
    }
    return dp[i][j][flag];
  }
};
