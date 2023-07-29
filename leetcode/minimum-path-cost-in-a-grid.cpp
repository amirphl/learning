// https://leetcode.com/problems/minimum-path-cost-in-a-grid/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
    int n = grid.size();
    int m = grid[0].size();
    int dp[n][m];
    int res = INT_MAX;

    for (int j = 0; j < m; j++) {
      dp[n - 1][j] = grid[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        int val = grid[i][j];
        int d = INT_MAX;

        for (int k = 0; k < m; k++) {
          d = min(d, moveCost[val][k] + dp[i + 1][k]);
        }

        dp[i][j] = val + d;

        if (i == 0) {
          res = min(res, dp[i][j]);
        }
      }
    }

    return res;
  }
};
