// https://leetcode.com/problems/longest-repeating-character-replacement/
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

int f[26];
class Solution {
public:
  int characterReplacement(string &s, int k) {
    int n = s.length();
    int res = 1;
    int w = 0;
    memset(f, 0, sizeof(f));
    for (int i = 0, j = 0; i < n; i++) {
      f[s[i] - 'A']++;
      w = max(w, f[s[i] - 'A']);
      if (i - j + 1 <= w + k) {
        res = max(res, w + k);
      } else {
        if (i == j) {
          j++;
          w = 0;
          continue;
        }
        f[s[i] - 'A']--;
        f[s[j] - 'A']--;
        i--;
        j++;
        w = *max_element(f, f + 26);
      }
    }
    return min(res, n);
  }
};
