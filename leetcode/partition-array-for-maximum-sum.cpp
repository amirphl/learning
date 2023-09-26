// https://leetcode.com/problems/partition-array-for-maximum-sum/
#include "bits/stdc++.h"
using namespace std;

int dp[500];
class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size(), t;
    int max_found = INT_MIN;

    for (int i = 0; i < k; i++) {
      max_found = max(max_found, arr[i]);
      dp[i] = max_found * (i + 1);
    }

    int i = k;
    for (; i < n; i++) {
      t = INT_MIN;
      max_found = arr[i];
      for (int j = 0; j < k; j++) {
        max_found = max(max_found, arr[i - j]);
        t = max(t, (j + 1) * max_found + dp[(i - j - 1 + k) % k]);
      }
      dp[i % k] = t;
    }

    return dp[(i - 1) % k];
  }
};
