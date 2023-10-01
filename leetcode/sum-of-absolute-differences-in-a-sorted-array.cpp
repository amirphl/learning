// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    int r0 = 0, x, y, z;
    for (int i = 1; i < n; i++) {
      r0 += nums[i] - nums[0];
    }
    res[0] = r0;
    x = 0;
    y = r0;
    for (int i = 1; i < n; i++) {
      z = nums[i] - nums[i - 1];
      x += i * z;
      y -= (n - i) * z;
      res[i] = x + y;
    }
    return res;
  }
};
