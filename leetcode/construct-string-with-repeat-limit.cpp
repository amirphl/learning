// https://leetcode.com/problems/construct-string-with-repeat-limit/
#include "bits/stdc++.h"
using namespace std;

int arr[26];
class Solution {
public:
  string repeatLimitedString(string &s, const int repeatLimit) {
    memset(arr, 0, sizeof(arr));
    for (auto &c : s) {
      arr[c - 'a']++;
    }
    int j = 0;
    for (int i = 25, k = 24, r = 0; i >= 0;) {
      if (arr[i] == 0) {
        i--;
        r = 0;
        continue;
      }
      if (r >= repeatLimit) {
        while (k >= 0 && (k >= i || arr[k] == 0)) {
          k--;
        }
        if (k == -1) {
          break;
        }
        s[j++] = 'a' + k;
        arr[k]--;
        r = 0;
        continue;
      }
      s[j++] = 'a' + i;
      arr[i]--;
      r++;
    }
    return s.substr(0, j);
  }
};
