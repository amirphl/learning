// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
#include "bits/stdc++.h"
using namespace std;

int dp[40][40][2];
class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int n = arr.size();
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--) {
      dp[i][i][1] = arr[i];
      for (int j = i + 1; j < n; j++) {
        dp[i][j][0] = INT_MAX;
        for (int k = i; k < j; k++) {
          int cand =
              dp[i][k][0] + dp[k + 1][j][0] + dp[i][k][1] * dp[k + 1][j][1];
          if (cand <= dp[i][j][0]) {
            dp[i][j][0] = cand;
            dp[i][j][1] = max(dp[i][k][1], dp[k + 1][j][1]);
          }
        }
      }
    }
    return dp[0][n - 1][0];
  }
};
