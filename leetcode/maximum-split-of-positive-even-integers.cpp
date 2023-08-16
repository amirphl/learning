// https://leetcode.com/problems/maximum-split-of-positive-even-integers/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum & 1) {
      return {};
    }
    finalSum = finalSum >> 1;
    uint64_t x = (uint64_t)(sqrt(8 * finalSum + 1) - 1) >> 1;
    vector<long long> res(x);
    uint64_t sum = 0;
    for (int i = 1; i <= x; i++) {
      res[i - 1] = i * 2;
      sum += i * 2;
    }
    if (sum != finalSum * 2) {
      res[x - 1] += finalSum * 2 - sum;
    }
    return res;
  }
};
