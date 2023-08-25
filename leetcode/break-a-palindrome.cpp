// https://leetcode.com/problems/break-a-palindrome/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  string breakPalindrome(string &pal) {
    int n = pal.length();
    if (n == 1) {
      return "";
    }
    for (int i = 0; i < n / 2 + 1; i++) {
      if (pal[i] != 'a') {
        if (i == n - i - 1) {
          break;
        }
        pal[i] = 'a';
        return pal;
      }
    }
    pal[n - 1] = 'b';
    return pal;
  }
};
