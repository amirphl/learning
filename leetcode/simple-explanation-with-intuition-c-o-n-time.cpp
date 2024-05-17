// https://leetcode.com/problems/minimum-array-length-after-pair-removals/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minLengthAfterRemovals(vector<int> &nums) {
    unordered_map<int, int> m;
    auto num_elems{nums.size()};
    int freq{0};
    for (auto &x : nums) {
      ++m[x];
      freq = max(freq, m[x]);
    }
    if (freq > (num_elems / 2)) {
      return 2 * freq - num_elems;
    }
    return num_elems % 2 == 1;
  }
};
