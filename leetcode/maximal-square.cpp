// https://leetcode.com/problems/maximal-square/description/
#include "bits/stdc++.h"
using namespace std;

int dp[300][300];
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (matrix[i][j] == '1') {
          int a = i < n - 1 ? dp[i + 1][j] : 0;
          int b = j < m - 1 ? dp[i][j + 1] : 0;
          dp[i][j] = 1 + min(a, b);
          if (a == b && matrix[i + a][j + b] == '0') {
            dp[i][j]--;
          }
          res = max(res, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return res * res;
  }
};
