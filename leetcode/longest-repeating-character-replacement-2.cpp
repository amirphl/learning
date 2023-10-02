// https://leetcode.com/problems/longest-repeating-character-replacement/
#include "bits/stdc++.h"
using namespace std;

bool f[26];
class Solution {
public:
  int characterReplacement(string &s, int k) {
    int n = s.length();
    int res = 1;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
      f[s[i] - 'A'] = 1;
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
      if (!f[ch - 'A']) {
        continue;
      }
      int w = 0;
      for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == ch) {
          w++;
        }
        if (i - j + 1 <= w + k) {
          res = max(res, w + k);
        } else {
          if (i == j) {
            j++;
            w = 0;
            continue;
          }
          if (s[j] == ch) {
            w--;
          }
          j++;
          if (s[i] == ch) {
            w--;
          }
          i--;
        }
      }
    }
    return min(res, n);
  }
};
