// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minInsertions(string &s) {
    int open = 0;
    int close = 0;
    int c = 0;
    for (auto &ch : s) {
      if (ch == '(') {
        if (close == 1) {
          if (open == 0) {
            c += 2;
          } else {
            c++;
            open--;
          }
        } else if (close == 2) {
          if (open == 0) {
            c++;
          } else {
            open--;
          }
        }
        open++;
        close = 0;
      } else {
        close++;
        if (close == 2) {
          if (open == 0) {
            c++;
          } else {
            open--;
          }
          close = 0;
        }
      }
    }
    if (close == 0) {
      c += open * 2;
    } else if (close == 1) {
      if (open == 0) {
        c += 2;
      } else {
        c++;
        open--;
        c += open * 2;
      }
    } else {
      if (open == 0) {
        c++;
      } else {
        open--;
        c += open * 2;
      }
    }
    return c;
  }
};

int main() {
  string s = "))()((())";
  Solution sol;
  cout << sol.minInsertions(s) << "\n";
  return 0;
}
