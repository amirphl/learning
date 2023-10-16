// https://leetcode.com/problems/sort-integers-by-the-power-value/
#include "bits/stdc++.h"
using namespace std;

const int N = 3002;
unordered_map<int, int> dp;
int arr[N];
class Solution {
public:
  int getKth(int lo, int hi, int k) {
    for (int i = lo; i <= hi; i++) {
      arr[i] = i;
      rec(i);
    }
    sort(arr + lo, arr + hi + 1, [](int x, int y) {
      return dp[x] < dp[y] || (dp[x] == dp[y] && x < y);
    });
    return arr[lo + k - 1];
  }

  int rec(int x) {
    if (dp.find(x) != dp.end()) {
      return dp[x];
    }
    if (x <= 1) {
      return dp[x] = 0;
    }
    if (x & 1) {
      return dp[x] = 1 + rec(3 * x + 1);
    }
    return dp[x] = 1 + rec(x / 2);
  }
};
