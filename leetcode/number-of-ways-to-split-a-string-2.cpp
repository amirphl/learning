// https://leetcode.com/problems/number-of-ways-to-split-a-string/
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;

  int numWays(string &s) {
    int n = s.length();
    int prefix[n];
    int mapping[n + 1];
    memset(mapping, 0, sizeof(mapping));
    prefix[0] = s[0] == '0' ? 0 : 1;
    mapping[prefix[0]] = 0;
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + (s[i] == '0' ? 0 : 1);
      if (mapping[prefix[i]] == 0) {
        mapping[prefix[i]] = i;
      }
    }
    uint64_t ans = 0;
    for (int i = 1; i < n - 1; i++) {
      int x = prefix[i - 1];
      int y = prefix[n - 1] - prefix[i - 1];
      if (2 * x != y) {
        continue;
      }
      if (x == 0) {
        ans = (ans + n - 1 - i) % mod;
        continue;
      }
      int d1 = mapping[2 * x];
      int d2 = mapping[2 * x + 1];
      ans = (ans - d1 + d2) % mod;
    }
    return ans;
  }
};
