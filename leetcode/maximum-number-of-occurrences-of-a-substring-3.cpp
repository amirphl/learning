// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<string, int> m;
    int n = s.length();
    int c = 0;
    int arr[26];
    int unique = 0;
    int idx;
    for (int w = minSize; w <= minSize; w++) {
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
          string pat = s.substr(i, w);
          m[pat]++;
          c = max(c, m[pat]);
        }
      }
    }
    return c;
  }
};
