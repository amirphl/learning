// https://leetcode.com/problems/jump-game-ii/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 0;
    }
    int temp = nums[0], max_reached = nums[0];
    int i = 0;
    int moves = 1;
    while (temp < n - 1 && i <= temp) {
      max_reached = max(max_reached, i + nums[i]);
      i++;
      if (i == temp + 1) {
        moves++;
        temp = max_reached;
      }
    }
    return moves;
  }
};
