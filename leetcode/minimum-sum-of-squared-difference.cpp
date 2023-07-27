// https://leetcode.com/problems/minimum-sum-of-squared-difference/
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  // TLE
  long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1,
                             int k2) {
    int n = nums1.size();
    uint64_t count = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
      int diff = abs(nums1[i] - nums2[i]);
      pq.push(diff);
    }

    int s = k1 + k2;

    while (s > 0 && !pq.empty()) {
      int x = pq.top();
      pq.pop();

      if (!pq.empty()) {
        int y = pq.top();

        if (x > y) {
          if (x - y >= s) {
            pq.push(x - s);
            s = 0;
          } else {
            pq.push(y);
            s -= x - y;
          }
        } else { // x == y
          if (x != 0) {
            pq.push(x - 1);
            s--;
          }
        }
      } else {
        if (x >= s) {
          pq.push(x - s);
          s = 0;
        } else {
          s = 0;
        }
      }
    }

    while (!pq.empty()) {
      count += (uint64_t)pq.top() * (uint64_t)pq.top();
      pq.pop();
    }

    return count;
  }
};

int main() {
  Solution sol;
  return 0;
}
