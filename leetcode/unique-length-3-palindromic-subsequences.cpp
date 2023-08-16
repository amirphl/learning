// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
#include "bits/stdc++.h"
#include <cstring>
using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string &s) {
    int n = s.length();
    bool prefix[n][26];
    bool suffix[n][26];
    memset(prefix, 0, sizeof(prefix));
    memset(suffix, 0, sizeof(suffix));
    for (int i = 0, k = n - 1; i < n; i++, k--) {
      if (i == 0) {
        prefix[i][s[i] - 'a'] = 1;
        suffix[k][s[k] - 'a'] = 1;
        continue;
      }
      for (int j = 0; j < 26; j++) {
        prefix[i][j] = prefix[i - 1][j];
        suffix[k][j] = suffix[k + 1][j];
      }
      prefix[i][s[i] - 'a'] = 1;
      suffix[k][s[k] - 'a'] = 1;
    }
    int M = 26 * 26;
    bool dp[M];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n - 1; i++) {
      int s1 = (s[i] - 'a') * 26;
      for (int j = 0; j < 26; j++) {
        if (prefix[i][j] && suffix[i][j]) {
          dp[s1 + j] = 1;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < M; i++) {
      if (dp[i]) {
        res++;
      }
    }
    return res;
  }
};
