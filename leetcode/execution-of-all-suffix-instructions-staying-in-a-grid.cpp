// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> executeInstructions(int n, vector<int> &startPos, string &s) {
    const int row = startPos[0];
    const int col = startPos[1];
    int m = s.length();
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
      int r = row;
      int c = col;
      int ans = 0;
      for (int j = i; j < m; j++) {
        char dir = s[j];
        if (dir == 'R') {
          c++;
          if (c == n) {
            break;
          }
        } else if (dir == 'L') {
          c--;
          if (c == -1) {
            break;
          }
        } else if (dir == 'U') {
          r--;
          if (r == -1) {
            break;
          }
        } else {
          r++;
          if (r == n) {
            break;
          }
        }
        ans++;
      }
      res[i] = ans;
    }
    return res;
  }
};
