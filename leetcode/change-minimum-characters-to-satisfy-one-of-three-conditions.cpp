// https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minCharacters(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    int s1_dp[26];
    int s2_dp[26];
    memset(s1_dp, 0, sizeof(s1_dp));
    memset(s2_dp, 0, sizeof(s2_dp));
    for (auto &ch : s1) {
      s1_dp[ch - 'a']++;
    }
    for (auto &ch : s2) {
      s2_dp[ch - 'a']++;
    }
    for (int i = 1; i < 26; i++) {
      s1_dp[i] += s1_dp[i - 1];
      s2_dp[i] += s2_dp[i - 1];
    }
    int res = INT_MAX;
    for (int i = 0; i < 25; i++) {
      res = min(res, n - s1_dp[i] + s2_dp[i]);
      res = min(res, m - s2_dp[i] + s1_dp[i]);
      res = min(res, n - (s1_dp[i] - (i > 0 ? s1_dp[i - 1] : 0)) + m -
                         (s2_dp[i] - (i > 0 ? s2_dp[i - 1] : 0)));
    }
    int i = 25;
    res = min(res, n - (s1_dp[i] - (i > 0 ? s1_dp[i - 1] : 0)) + m -
                       (s2_dp[i] - (i > 0 ? s2_dp[i - 1] : 0)));
    if (res == INT_MAX) {
      res = 0;
    }
    return res;
  }
};
