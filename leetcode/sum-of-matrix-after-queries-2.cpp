// https://leetcode.com/problems/sum-of-matrix-after-queries/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  long long matrixSumQueries(int n, vector<vector<int>> &queries) {
    char row[n];
    char col[n];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    uint64_t r = 0, c = 0;
    uint64_t sum = 0;
    for (auto it = queries.rbegin(); it != queries.rend(); it++) {
      int t = it->at(0);
      int idx = it->at(1);
      int val = it->at(2);
      if (t == 0 && row[idx] == 0) {
        sum += (n - c) * val;
        row[idx] = 1;
        r++;
      }
      if (t == 1 && col[idx] == 0) {
        sum += (n - r) * val;
        col[idx] = 1;
        c++;
      }
    }
    return sum;
  }
};
