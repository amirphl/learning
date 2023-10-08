// https://leetcode.com/problems/satisfiability-of-equality-equations/
#include "bits/stdc++.h"
using namespace std;

int arr[128];
class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    memset(arr, -1, sizeof(arr));
    char ch1, ch2, p1, p2;
    for (auto &e : equations) {
      ch1 = e[0];
      ch2 = e[3];
      if (e[1] == '=') {
        if (ch1 == ch2) {
          continue;
        }
        p1 = parent(ch1);
        p2 = parent(ch2);
        if (p1 == p2) {
          continue;
        }
        arr[p1] = p2;
      }
    }
    for (auto &e : equations) {
      ch1 = e[0];
      ch2 = e[3];
      if (e[1] == '!') {
        if (ch1 == ch2) {
          return 0;
        }
        p1 = parent(ch1);
        p2 = parent(ch2);
        if (p1 == p2) {
          return 0;
        }
      }
    }
    return 1;
  }

  int parent(char ch) {
    if (arr[ch] == -1) {
      return ch;
    }
    return arr[ch] = parent(arr[ch]);
  }
};
