// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int c = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (matrix[i][j]) {
          int d = 1;
          for (int k = 1; i + k < n && j + k < m && matrix[i + k][j] &&
                          matrix[i][j + k] && matrix[i + 1][j + 1] >= k;
               k++, d++)
            ;
          c += d;
          matrix[i][j] = d;
        }
      }
    }
    return c;
  }
};
