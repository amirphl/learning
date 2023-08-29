// https://leetcode.com/problems/swap-adjacent-in-lr-string/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  bool canTransform(string start, string end) {
    int n = start.length();
    for (int i = 0; i < n; i++) {
      if (start[i] == end[i]) {
        continue;
      }
      if (start[i] == 'R') {
        if (end[i] == 'L') {
          return 0;
        }
        // X
        int j = i + 1;
        for (; j < n; j++) {
          if (start[j] == 'L' || start[j] == 'X') {
            break;
          }
        }
        if (j == n || start[j] == 'L') {
          return 0;
        }
        start[j] = 'R';
        start[i] = 'X';
      } else if (start[i] == 'L') {
        return 0;
      } else { // X
        if (end[i] == 'R') {
          return 0;
        }
        // L
        int j = i + 1;
        for (; j < n; j++) {
          if (start[j] == 'L' || start[j] == 'R') {
            break;
          }
        }
        if (j == n || start[j] == 'R') {
          return 0;
        }
        start[j] = 'X';
        start[i] = 'L';
      }
    }
    return 1;
  }
};
