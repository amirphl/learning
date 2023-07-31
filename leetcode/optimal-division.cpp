// https://leetcode.com/problems/optimal-division/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  string optimalDivision(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return to_string(nums[0]);
    }
    if (n == 2) {
      return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    string scnd_part = "(";
    for (int i = 1; i < n; i++) {
      scnd_part += to_string(nums[i]) + (i == n - 1 ? ")" : "/");
    }

    return to_string(nums[0]) + "/" + scnd_part;
  }
};
