// https://leetcode.com/problems/minimum-increment-to-make-array-unique/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minIncrementForUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int c = 0, d = nums[0];
    int moves = 0;
    for (int i = 0; i < n;) {
      if (nums[i] < d) {
        moves += d + 1 - nums[i];
        d++;
        c = 1;
        i++;
        continue;
      }
      if (nums[i] > d) {
        d = nums[i];
        c = 1;
        i++;
        continue;
      }
      while (i < n && nums[i] == d) {
        i++;
        c++;
      }
      moves += c * (c - 1) / 2;
      d += c - 1;
      c = 1;
    }
    return moves;
  }
};
