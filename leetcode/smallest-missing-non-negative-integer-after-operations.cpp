// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int findSmallestInteger(vector<int> &nums, int value) {
    int arr[value];
    memset(arr, 0, sizeof(arr));

    for (auto &x : nums) {
      if (x < 0) {
        x += ((-x / value) + 1) * value;
      }
      arr[x % value]++;
    }

    int m = INT_MAX, j;

    for (int i = 0; i < value; i++) {
      if (arr[i] < m) {
        m = arr[i];
        j = i;
      }
    }

    return m * value + j;
  }
};
