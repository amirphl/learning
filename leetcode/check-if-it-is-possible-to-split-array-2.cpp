// https://leetcode.com/problems/check-if-it-is-possible-to-split-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  bool canSplitArray(vector<int> &arr, int m) {
    int n = arr.size();
    if (n < 3) {
      return 1;
    }
    int sum = arr[0];
    for (int i = 1; i < n; i++) {
      sum += arr[i];
      if (sum >= m) {
        return 1;
      }
      sum -= arr[i - 1];
    }
    return 0;
  }
};
