// https://leetcode.com/problems/minimum-sideway-jumps/
#include "bits/stdc++.h"
using namespace std;

const int K = 3;
class Solution {
public:
  int minSideJumps(vector<int> &obstacles) {
    int n = obstacles.size();
    int dp[K];
    int dp2[K];
    int next;
    memset(dp, 0, sizeof(dp));
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < K; j++) {
        dp2[j] = INT_MAX;
        if (obstacles[i] - 1 == j) {
          continue;
        }
        dp2[j] = dp[j];
        next = (j + 1) % K;
        if (obstacles[i] - 1 != next && dp[next] != INT_MAX) {
          dp2[j] = min(dp2[j], 1 + dp[next]);
        }
        next = (j + 2) % K;
        if (obstacles[i] - 1 != next && dp[next] != INT_MAX) {
          dp2[j] = min(dp2[j], 1 + dp[next]);
        }
      }
      for (int j = 0; j < K; j++) {
        dp[j] = dp2[j];
      }
    }
    return dp[1];
  }
};
