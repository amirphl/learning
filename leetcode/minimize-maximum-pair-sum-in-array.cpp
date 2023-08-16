// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minPairSum(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    uint64_t res = INT_MAX;
    uint64_t t;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      t = arr[i] + arr[j];
      if (t < res) {
        res = t;
      }
    }
    return res;
  }
};
