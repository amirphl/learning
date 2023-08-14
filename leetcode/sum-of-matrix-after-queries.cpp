// https://leetcode.com/problems/sum-of-matrix-after-queries/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // TLE
  long long matrixSumQueries(int n, vector<vector<int>> &queries) {
    int row[n][2];
    int col[n][2];
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));
    int i = 0;
    for (auto &q : queries) {
      int t = q[0];
      int idx = q[1];
      int val = q[2];
      if (t == 0) {
        row[idx][0] = val;
        row[idx][1] = i;
      } else {
        col[idx][0] = val;
        col[idx][1] = i;
      }
      i++;
    }
    uint64_t sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (row[i][0] != -1 && col[j][0] != -1) {
          sum += row[i][1] < col[j][1] ? col[j][0] : row[i][0];
        } else if (row[i][0] != -1) {
          sum += row[i][0];
        } else if (col[j][0] != -1) {
          sum += col[j][0];
        }
      }
    }
    return sum;
  }
};
