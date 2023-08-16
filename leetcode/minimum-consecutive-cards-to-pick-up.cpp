// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  const int LIMIT = 1e6 + 1;
  int minimumCardPickup(vector<int> &cards) {
    int arr[LIMIT];
    memset(arr, -1, sizeof(arr));
    int n = cards.size();
    int res = n + 1;
    for (int i = 0, j = 0; i < n; i++) {
      if (arr[cards[i]] == -1 || arr[cards[i]] < j) {
        arr[cards[i]] = i;
        continue;
      }
      int k = arr[cards[i]];
      res = min(res, i - k + 1);
      j = k + 1;
      arr[cards[i]] = i;
    }
    if (res == n + 1) {
      return -1;
    }
    return res;
  }
};
