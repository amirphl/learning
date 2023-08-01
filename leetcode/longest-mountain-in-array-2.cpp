// https://leetcode.com/problems/longest-mountain-in-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    if (n < 3) {
      return 0;
    }
    int i = 1;
    for (; i < n; i++) {
      if (arr[i - 1] < arr[i]) {
        break;
      }
    }
    int UP = 0, FLAT = 1, DOWN = 2;
    int state = UP;
    int j = i - 1;
    int res = INT_MIN;

    for (; i < n - 1; i++) {
      if (arr[i] < arr[i + 1]) {
        if (state == UP) {
        } else if (state == FLAT) {
          j = i;
        } else {
          if (j != -1) {
            res = max(res, i - j + 1);
          }
          j = i;
        }
        state = UP;
      } else if (arr[i] == arr[i + 1]) {
        if (state == UP) {
          j = -1;
        } else if (state == FLAT) {
          j = -1;
        } else {
          if (j != -1) {
            res = max(res, i - j + 1);
          }
          j = -1;
        }
        state = FLAT;
      } else {
        if (state == UP) {
        } else if (state == FLAT) {
          j = -1;
        } else {
        }
        state = DOWN;
      }
    }
    if (state == DOWN && j != -1) {
      res = max(res, i - j + 1);
    }
    return res < 3 ? 0 : res;
  }
};
