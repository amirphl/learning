// https://leetcode.com/problems/check-if-it-is-possible-to-split-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // wrong answer
  bool canSplitArray2(vector<int> &arr, int m) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if ((i + 1 < n && arr[i] + arr[i + 1] >= m) ||
          (0 <= i - 1 && arr[i - 1] + arr[i] >= m) ||
          (0 <= i - 2 && arr[i - 2] + arr[i - 1] >= m) ||
          (i + 2 < n && arr[i + 1] + arr[i + 2] >= m)) {
        continue;
      }
      return false;
    }
    return true;
  }

  bool canSplitArray(vector<int> &arr, int m) {
    int n = arr.size();
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + arr[i];
    }
    char dp[n][n];
    for (int i = n - 1; i >= 0; i--) {
      dp[i][i] = 1;
      if (i + 1 < n) {
        dp[i][i + 1] = 1;
      }
      for (int j = i + 2; j < n; j++) {
        dp[i][j] = 0;
        for (int k = i + 1; k <= j; k++) {
          int p1 = prefix[k - 1] - (0 < i ? prefix[i - 1] : 0);
          int p2 = prefix[j] - prefix[k - 1];
          if (dp[i][k - 1] && dp[k][j] && (k - i == 1 || m <= p1) &&
              (j - k + 1 == 1 || m <= p2)) {
            dp[i][j] = 1;
            break;
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};
