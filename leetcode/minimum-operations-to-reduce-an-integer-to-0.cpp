// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/
#include "bits/stdc++.h"
using namespace std;

// THIS DOESN'T WORK

const int N = 20;
uint64_t powers[N];
unordered_map<uint64_t, int> DP;
class Solution {
public:
  int minOperations(int x) {
    powers[0] = 1;
    for (int i = 1; i < N; i++) {
      powers[i] = 2 * powers[i - 1];
    }
    return rec(x);
  }
  int rec(int x) {
    if (DP.find(x) != DP.end()) {
      return DP[x];
    }
    if (x < 0) {
      return INT_MAX;
    }
    if (x == 0) {
      return DP[x] = 0;
    }
    if (x == 1) {
      return DP[x] = 1;
    }
    int res = INT_MAX;
    for (int i = 0; i < N; i++) {
      res = min({res, rec(x - powers[i]), rec(x + powers[i])});
    }
    return DP[x] = res + 1;
  }
};
