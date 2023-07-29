// https://leetcode.com/problems/count-the-number-of-fair-pairs/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    uint64_t res = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0, j = n - 1; i < j; i++) {
      // nums[i] + nums[j] <= upper
      // nums[j] <= upper - nums[i]
      int a = upper - nums[i]; // nums[j] <= a
      while (i < j && nums[j] > a) {
        j--;
      }
      res += j - i;
    }

    for (int i = 0, j = n - 1; i < j; i++) {
      // nums[i] + nums[j] < lower
      // nums[j] < lower - nums[i]
      int a = lower - nums[i]; // nums[j] < a
      while (i < j && nums[j] >= a) {
        j--;
      }
      res -= j - i;
    }

    return res;
  }
};
