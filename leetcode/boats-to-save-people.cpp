// https://leetcode.com/problems/boats-to-save-people/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &p, int limit) {
    int n = p.size();
    sort(p.begin(), p.end());
    int count = 0;
    int invalid = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (p[i] > limit || p[i] < 0) {
        if (p[i] > limit) {
          invalid++;
        }
        continue;
      }
      int x = limit - p[i];
      p[i] = -p[i];
      if (x == 0) {
        count++;
        continue;
      }
      int pos = bs(p, x, 0, n - 1 - invalid);
      if (pos != -1) {
        p[pos] = -p[pos];
      }
      count++;
    }
    return count;
  }

  int bs(vector<int> &p, const int x, int low, int high) {
    while (low <= high) {
      if (low == high) {
        if (0 < p[low] && p[low] <= x) {
          return low;
        }
        return -1;
      }
      int mid = low + ((high - low) >> 1);
      if (p[mid] < 0) {
        int y = -p[mid];
        if (x < y) {
          high = mid - 1;
        } else {
          int right = bs(p, x, mid + 1, high);
          if (right != -1) {
            return right;
          }
          return bs(p, x, low, mid - 1);
        }
      } else if (p[mid] <= x) {
        int right = bs(p, x, mid + 1, high);
        if (right != -1) {
          return right;
        }
        return mid;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
};
