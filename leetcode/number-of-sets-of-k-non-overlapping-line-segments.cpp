// https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;
  // TLE
  int numberOfSets2(const int n, const int k) {
    uint64_t dp[n][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
      dp[i][1] = (i * (i + 1) / 2) % mod;
      for (int j = 2; j <= min(i, k); j++) {
        dp[i][j] = dp[i - 1][j];
        for (int u = 1; u < i; u++) {
          dp[i][j] = (dp[i][j] + dp[u][j - 1]) % mod;
        }
      }
    }
    return dp[n - 1][k];
  }

  int numberOfSets(const int n, const int k) {
    uint64_t dp[n][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
      dp[i][1] = (i * (i + 1) / 2) % mod;
      for (int j = 2; j <= min(i, k); j++) {
        dp[i][j] =
            (2 * dp[i - 1][j] + dp[i - 1][j - 1] - dp[i - 2][j] + mod) % mod;
      }
    }
    return dp[n - 1][k];
  }
};
