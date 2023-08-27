// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minSumOfLengths(vector<int> &arr, int target) {
    int n = arr.size();
    uint64_t prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + arr[i];
    }
    int dp[n];
    dp[n - 1] = target == arr[n - 1] ? 1 : -1;
    for (int i = n - 2; i >= 0; i--) {
      dp[i] = dp[i + 1];
      int x = (i > 0 ? prefix[i - 1] : 0) + target;
      int idx = lower_bound(prefix + i, prefix + n, x) - prefix;
      if (idx == n || prefix[idx] != x) {
        continue;
      }
      int len = idx - i + 1;
      if (dp[i] == -1) {
        dp[i] = len;
      } else {
        dp[i] = min(dp[i], len);
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int x = (i > 0 ? prefix[i - 1] : 0) + target;
      int idx = lower_bound(prefix + i, prefix + n, x) - prefix;
      if (idx >= n - 1 || prefix[idx] != x) {
        continue;
      }
      int len = idx - i + 1;
      int len2 = dp[idx + 1];
      if (len2 != -1)
        ans = min(ans, len + len2);
    }
    if (ans == INT_MAX) {
      return -1;
    }
    return ans;
  }
};
