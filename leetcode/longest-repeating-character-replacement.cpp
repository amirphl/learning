// https://leetcode.com/problems/longest-repeating-character-replacement/
#include "bits/stdc++.h"
using namespace std;

int f[26];
class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.length();
    int low = 1, high = n, mid;
    int i;
    int max_found;
    while (low < high) {
      mid = low + (high - low) / 2;
      if (low + 1 == high) {
        mid = high;
      }
      memset(f, 0, sizeof(f));
      max_found = 0;
      for (int i = 0; i < mid; i++) {
        f[s[i] - 'A']++;
        max_found = max(max_found, f[s[i] - 'A']);
      }
      if (mid <= max_found + k) {
        low = mid;
        continue;
      }
      for (i = mid; i < n; i++) {
        f[s[i - mid] - 'A']--;
        f[s[i] - 'A']++;
        max_found = *max_element(f, f + 26);
        if (mid <= max_found + k) {
          break;
        }
      }
      if (i == n) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    return low;
  }
};
