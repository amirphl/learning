// https://leetcode.com/problems/guess-number-higher-or-lower-ii/
#include "bits/stdc++.h"
using namespace std;

int dp[200 + 2][200 + 2];

class Solution {
public:
  int getMoneyAmount(int n) {
    memset(dp, 0, sizeof(dp));
    for (int i = n; i > 0; i--) {
      dp[i][i] = 0;
      for (int j = i + 1; j <= n; j++) {
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; k++) {
          dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
        }
      }
    }
    return dp[1][n];
  }
};
