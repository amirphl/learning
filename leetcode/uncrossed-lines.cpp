// https://leetcode.com/problems/uncrossed-lines/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int dp[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (nums1[i] == nums2[j]) {
          dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
        } else {
          dp[i][j] = max(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0);
        }
      }
    }
    return dp[n - 1][m - 1];
  }
};
