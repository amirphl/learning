// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int n;
  int delay, forget;
  int mod = 1e9 + 7;
  int peopleAwareOfSecret(int n, int delay, int forget) {
    this->n = n;
    this->delay = delay;
    this->forget = forget;
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    rec(dp, 1);
    return dp[1];
  }

  void rec(int dp[], int idx) {
    if (dp[idx] != -1) {
      return;
    }
    if (idx > n) {
      return;
    }
    int res = 0;
    for (int i = idx + delay; i < idx + forget && i < n + 1; i++) {
      rec(dp, i);
      res = (res + dp[i]) % mod;
    }
    if (idx + forget > n) {
      res = (res + 1) % mod;
    }
    dp[idx] = res;
  }
};
