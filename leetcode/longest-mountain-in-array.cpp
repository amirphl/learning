// https://leetcode.com/problems/longest-mountain-in-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    int lis[n];
    int lds[n];
    lis[0] = 1;
    lds[n - 1] = 1;

    for (int i = 1; i < n; i++) {
      if (arr[i - 1] < arr[i]) {
        lis[i] = lis[i - 1] + 1;
      } else {
        lis[i] = 1;
      }
      if (arr[n - i - 1] > arr[n - i]) {
        lds[n - i - 1] = lds[n - i] + 1;
      } else {
        lds[n - i - 1] = 1;
      }
    }
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (lis[i] == 1 || lds[i] == 1) {
        continue;
      }
      res = max(res, lis[i] + lds[i] - 1);
    }
    return res < 3 ? 0 : res;
  }
};
