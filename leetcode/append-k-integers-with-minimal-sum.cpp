// https://leetcode.com/problems/append-k-integers-with-minimal-sum/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  long long minimalKSum(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    uint64_t res = 0, j = 1;
    for (int i = 0; i < n;) {
      if (i == n || j < nums[i]) {
        res += j;
        k--;
        if (k == 0) {
          break;
        }
      } else {
        int u = i;
        i++;
        while (i < n && nums[i] == nums[u]) {
          i++;
        }
      }
      j++;
    }
    uint64_t c = k;
    res += c * j + c * (c - 1) / 2;
    return res;
  }
};
