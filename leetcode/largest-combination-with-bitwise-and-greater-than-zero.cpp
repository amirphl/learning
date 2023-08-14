// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int largestCombination(vector<int> &cand) {
    int n = cand.size();
    int arr[32];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
      int x = cand[i];
      for (int j = 0; j < 32; j++) {
        if (x & 1) {
          arr[j]++;
        }
        x = x >> 1;
      }
    }
    return *max_element(arr, arr + 32);
  }
};
