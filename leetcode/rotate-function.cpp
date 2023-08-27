// https://leetcode.com/problems/rotate-function/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    int n = nums.size();
    int64_t A = 0;
    int64_t f = 0;
    for (int i = 0; i < n; i++) {
      A += nums[i];
      f += i * nums[i];
    }
    int64_t ans = f;
    for (int i = 1; i < n; i++) {
      int64_t next = f + A - n * nums[n - i];
      if (ans < next) {
        ans = next;
      }
      f = next;
    }
    return ans;
  }
};
