// https://leetcode.com/problems/increment-submatrices-by-one/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto &q : queries) {
      int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
      mat[r1][c1]++;

      if (r2 < n - 1)
        mat[r2 + 1][c1]--;
      if (c2 < n - 1)
        mat[r1][c2 + 1]--;
      if (r2 < n - 1 && c2 < n - 1)
        mat[r2 + 1][c2 + 1]++;
    }

    int cum = 0;

    for (int i = 0; i < n; i++) {
      cum = 0;

      for (int j = i; j < n; j++) {
        cum += mat[i][j];

        if (i < j && i < n - 1) {
          mat[i + 1][j] += mat[i][j];
        }

        mat[i][j] = cum;
      }

      cum = 0;

      for (int j = i; j < n; j++) {
        cum += mat[j][i];

        if (i < j && i < n - 1) {
          mat[j][i + 1] += mat[j][i];
        }

        mat[j][i] = cum;
      }

      if (i < n - 1)
        mat[i + 1][i + 1] += mat[i][i];
    }

    return mat;
  }
};
