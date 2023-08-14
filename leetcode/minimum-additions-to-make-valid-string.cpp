// https://leetcode.com/problems/minimum-additions-to-make-valid-string/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int addMinimum(string &word) {
    int n = word.length();
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (i < n - 2 && word.substr(i, 3) == "abc") {
        i += 2;
        continue;
      }
      char ch = word[i];
      if (ch == 'a') {
        if (i < n - 1) {
          if (word[i + 1] == 'b' || word[i + 1] == 'c') {
            res += 1;
            i++;
          } else {
            res += 2;
          }
        } else {
          res += 2;
        }
      } else if (ch == 'b') {
        if (i < n - 1) {
          if (word[i + 1] == 'c') {
            res += 1;
            i++;
          } else {
            res += 2;
          }
        } else {
          res += 2;
        }
      } else {
        res += 2;
      }
    }
    return res;
  }
};
