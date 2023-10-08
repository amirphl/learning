// https://leetcode.com/problems/maximum-alternating-subsequence-sum/
#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;
int64_t dp[N];
class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {
    dp[0] = nums[0];
    int n = nums.size();
    int64_t t, sub, sub2 = INT_MIN;
    for (int i = 1; i < n; i++) {
      sub = max(dp[i - 1], nums[i]);
      if (i > 1) {
        sub2 = max(sub2, dp[i - 2] - nums[i - 1]);
      }
      dp[i] = max(sub, sub2 + nums[i]);
    }
    return dp[n - 1];
  }

  int64_t max(int64_t x, int64_t y) { return x > y ? x : y; }
};
