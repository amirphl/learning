// https://leetcode.com/problems/maximum-subarray/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int max_sum = nums[0];
    int curr_sum = nums[0];
    int i = 1;
    for (; i < n; i++) {
      if (curr_sum > 0) {
        break;
      }
      curr_sum = max(curr_sum, nums[i]);
      max_sum = max(max_sum, nums[i]);
    }
    for (; i < n; i++) {
      curr_sum += nums[i];
      if (curr_sum <= 0) {
        curr_sum = 0;
      }
      max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
  }
};
