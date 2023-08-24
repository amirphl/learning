// https://leetcode.com/problems/number-of-ways-to-split-a-string/
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;
  // TLE
  int numWays2(string &s) {
    int n = s.length();
    int prefix[n];
    prefix[0] = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + (s[i] == '0' ? 0 : 1);
    }
    uint64_t ans = 0;
    for (int i = 1; i < n - 1; i++) {
      for (int j = i; j < n - 1; j++) {
        int x = prefix[j] - prefix[i - 1];
        if (prefix[i - 1] == x && x == prefix[n - 1] - prefix[j]) {
          ans = (ans + 1) % mod;
        }
      }
    }
    return ans;
  }

  int numWays(string &s) {
    int n = s.length();
    int prefix[n];
    prefix[0] = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + (s[i] == '0' ? 0 : 1);
    }
    uint64_t ans = 0;
    for (int i = 1; i < n - 1; i++) {
      int x = prefix[i - 1];
      int y = prefix[n - 1] - prefix[i - 1];
      if (2 * x != y) {
        continue;
      }
      int d1 = lower_bound(prefix + i, prefix + n - 1, 2 * x) - prefix;
      int d2 = upper_bound(prefix + i, prefix + n - 1, 2 * x) - prefix;
      ans = (ans - d1 + d2) % mod;
    }
    return ans;
  }
};
