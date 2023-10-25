// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> maxScoreIndices(vector<int> &nums) {
    int n = nums.size();
    int zeros = 0;
    int ones = 0;
    for (auto &x : nums) {
      if (x == 1)
        ones += x;
    }
    int score = ones;
    vector<int> res;

    res.push_back(0);

    for (int i = 0; i < n; i++) {
      int x = nums[i];

      switch (x) {
      case 0:
        zeros++;
        break;
      default:
        ones--;
        break;
      }

      int total = zeros + ones;

      if (total == score) {
        res.push_back(i + 1);
      } else if (total > score) {
        score = total;
        res.clear();
        res.push_back(i + 1);
      }
    }

    return res;
  }
};
