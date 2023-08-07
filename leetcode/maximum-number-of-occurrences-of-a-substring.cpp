// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // TLE
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int n = s.length();
    int c = 0;
    int arr[26];
    int unique = 0;
    int idx;
    for (int w = minSize; w <= maxSize; w++) {
      memset(arr, 0, sizeof(arr));
      unique = 0;
      for (int i = 0; i + w - 1 < n; i++) {
        if (i == 0) {
          for (int k = 0; k < w; k++) {
            idx = s[k] - 'a';
            if (arr[idx] == 0) {
              unique++;
            }
            arr[idx]++;
          }
        }
        if (i > 0) {
          idx = s[i - 1] - 'a';
          arr[idx]--;
          if (arr[idx] == 0) {
            unique--;
          }
          idx = s[i + w - 1] - 'a';
          if (arr[idx] == 0) {
            unique++;
          }
          arr[idx]++;
        }
        if (unique <= maxLetters) {
          c = max(c, count(s, i, i + w - 1));
        }
      }
    }
    return c;
  }

  int count(string &s, const int low, const int high) {
    int n = s.length();
    int w = high - low + 1;
    int c = 0;

    for (int i = 0; i + w - 1 < n; i++) {
      int j = 0;
      for (; j < w; j++) {
        if (s[i + j] != s[low + j]) {
          break;
        }
      }
      if (j == w) {
        c++;
      }
    }

    return c;
  }
};
