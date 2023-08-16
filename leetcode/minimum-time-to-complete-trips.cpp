// https://leetcode.com/problems/minimum-time-to-complete-trips/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    uint64_t low = 1;
    uint64_t high = (uint64_t)1 << 52;
    while (low < high) {
      uint64_t mid = low + ((high - low) >> 1);
      uint64_t sum = 0;
      for (auto &t : time) {
        sum += mid / t;
      }
      if (sum < totalTrips) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
