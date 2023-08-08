// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size();
    int suffix[n];
    suffix[0] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      suffix[i] = suffix[i - 1] + nums[n - i - 1];
    }
    for (int i = 1; i < n; i++) {
      nums[i] += nums[i - 1];
    }
    int c = INT_MAX;
    int idx = lower_bound(suffix, suffix + n, x) - suffix;
    if (idx < n && suffix[idx] == x) {
      c = idx + 1;
    }
    for (int i = 0; i < n; i++) {
      int y = x - nums[i];
      if (y < 0) {
        break;
      }
      if (y == 0) {
        c = min(c, i + 1);
        break;
      }
      idx = lower_bound(suffix, suffix + n, y) - suffix;
      if (i < n - idx - 1 && suffix[idx] == y) {
        c = min(c, i + 1 + idx + 1);
      }
    }
    if (c == INT_MAX) {
      return -1;
    }
    return c;
  }
};
