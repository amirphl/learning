// https://leetcode.com/problems/largest-sum-of-averages/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // This solves exactly k partitions.
  double largestSumOfAverages2(vector<int> &nums, int k) {
    int n = nums.size();
    uint64_t prefix[n];
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }
    double dp[n][k + 1];
    for (int i = 0; i < n; i++) {
      dp[i][1] = prefix[i] * 1.0 / (i + 1);
      for (int j = 2; j <= min(i + 1, k); j++) {
        double temp = 0;
        for (int u = i; u >= j - 1; u--) {
          double t1 = (prefix[i] - prefix[u - 1]) * 1.0 / (i - u + 1);
          double t2 = dp[u - 1][j - 1];
          if (temp < t1 + t2) {
            temp = t1 + t2;
          }
        }
        dp[i][j] = temp;
      }
    }
    return dp[n - 1][k];
  }

  double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();
    uint64_t prefix[n];
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }
    double dp[n][k + 1];
    for (int i = 0; i < n; i++) {
      dp[i][1] = prefix[i] * 1.0 / (i + 1);
      for (int j = 2; j <= k; j++) {
        double temp = dp[i][j - 1];
        for (int u = i; u > 0; u--) {
          double t1 = (prefix[i] - prefix[u - 1]) * 1.0 / (i - u + 1);
          double t2 = dp[u - 1][j - 1];
          if (temp < t1 + t2) {
            temp = t1 + t2;
          }
        }
        double t3 = prefix[i] * 1.0 / (i + 1);
        if (temp < t3) {
          temp = t3;
        }
        dp[i][j] = temp;
      }
    }
    return dp[n - 1][k];
  }
};
