// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
#include "bits/stdc++.h"
using namespace std;

const int N = 26;
int u[N];
int v[N];
class Solution {
public:
  int minSteps(string &s, string &t) {
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    for (auto &ch : s) {
      u[ch - 'a']++;
    }
    for (auto &ch : t) {
      v[ch - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans += abs(u[i] - v[i]);
    }
    return ans / 2;
  }
};
