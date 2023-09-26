// https://leetcode.com/problems/triangle/
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &arr) {
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) {
      int m = arr[i].size();
      for (int j = 0; j < m; j++) {
        arr[i][j] += min(arr[i + 1][j], arr[i + 1][j + 1]);
      }
    }
    return *min_element(arr[0].begin(), arr[0].end());
  }
};
