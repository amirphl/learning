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
    for (int idx = n; idx > 0; idx--) {
      int res = (idx + forget) > n;
      int ran = min(idx + forget, n + 1);
      for (int i = idx + delay; i < ran; i++) {
        res = (res + dp[i]) % mod;
      }
      dp[idx] = res;
    }
    return dp[1];
  }
};
