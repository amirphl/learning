// https://leetcode.com/problems/largest-plus-sign/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    int arr[n][n][5];
    memset(arr, -1, sizeof(arr));
    for (auto &m : mines) {
      int x = m[0];
      int y = m[1];
      arr[x][y][0] = 0;

      // up
      for (int i = x + 1; i < n && arr[i][y] != 0; i++) {
        if (arr[i][y][1] == -1)
          arr[i][y][1] = i - x;
        else
          arr[i][y][1] = min(arr[i][y][1], i - x);
      }

      // down
      for (int i = x - 1; i >= 0 && arr[i][y] != 0; i--) {
        if (arr[i][y][2] == -1)
          arr[i][y][2] = x - i;
        else
          arr[i][y][2] = min(arr[i][y][2], x - i);
      }

      // left
      for (int i = y + 1; i < n && arr[x][i] != 0; i++) {
        if (arr[x][i][3] == -1)
          arr[x][i][3] = i - y;
        else
          arr[x][i][3] = min(arr[x][i][3], i - y);
      }

      // right
      for (int i = y - 1; i >= 0 && arr[x][i] != 0; i--) {
        if (arr[x][i][4] == -1)
          arr[x][i][4] = y - i;
        else
          arr[x][i][4] = min(arr[x][i][4], y - i);
      }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (arr[i][j][0] == 0) {
          continue;
        }
        int d = INT_MAX;
        for (int k = 1; k < 5; k++) {
          int c = arr[i][j][k];
          if (c == -1) {
            if (k == 1) {
              c = i + 1;
            } else if (k == 2) {
              c = n - i;
            } else if (k == 3) {
              c = j + 1;
            } else {
              c = n - j;
            }
          }
          d = min(d, c);
        }
        res = max(res, d);
      }
    }

    return res;
  }
};
