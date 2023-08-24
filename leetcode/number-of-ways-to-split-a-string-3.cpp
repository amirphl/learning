// https://leetcode.com/problems/number-of-ways-to-split-a-string/
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;

  int numWays(string &s) {
    int n = s.length();
    int mapping[100001];
    int prefix = s[0] == '0' ? 0 : 1;
    mapping[prefix] = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == '1') {
        prefix++;
        mapping[prefix] = i;
      }
    }
    uint64_t ans = 0;
    int x = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < n - 1; i++) {
      int y = prefix - x;
      if (2 * x != y) {
        x += (s[i] == '0' ? 0 : 1);
        continue;
      }
      if (x == 0) {
        ans = (ans + n - 1 - i) % mod;
        x += (s[i] == '0' ? 0 : 1);
        continue;
      }
      int d1 = mapping[2 * x];
      int d2 = mapping[2 * x + 1];
      ans = (ans - d1 + d2) % mod;
      x += (s[i] == '0' ? 0 : 1);
    }
    return ans;
  }
};
