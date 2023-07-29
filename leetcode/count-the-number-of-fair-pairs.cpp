// https://leetcode.com/problems/count-the-number-of-fair-pairs/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // TLE
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    multiset<int> s;
    int n = nums.size();
    uint64_t res = 0;

    for (int i = n - 1; i >= 0; i--) {
      int low = lower - nums[i];
      int high = upper - nums[i];
      auto x = lower_bound(s.begin(), s.end(), low);
      auto y = upper_bound(s.begin(), s.end(), high);
      int d = distance(x, y);
      res += d;
      s.insert(nums[i]);
    }

    return res;
  }
};
