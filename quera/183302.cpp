#include "bits/stdc++.h"
using namespace std;

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int a, c, g, t;
  cin >> a >> c >> g >> t;

  int n = s1.length(), m = s2.length();
  int dp[n][m];

  map<int, int> cost = {
    {'A', a},
    {'T', t},
    {'C', c},
    {'G', g},
  };

  int suffix[m];
  suffix[m - 1] = cost[s2[m - 1]];
  for(int i = m - 2; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + cost[s2[i]];
  }

  for(int i = n - 1; i >= 0; i--) {
    for(int j = m - 1; j >= 0; j--) {
      if (s1[i] == s2[j]) {
        if (i + 1 < n && j + 1 < m) {
          dp[i][j] = dp[i + 1][j + 1];
        } else if (i + 1 < n) {
          dp[i][j] = 0;
        } else if (j + 1 < m) {
          dp[i][j] = suffix[j + 1];
        } else {
          dp[i][j] = 0;
        }
      } else {
        if (j + 1 < m) {
          dp[i][j] = dp[i][j + 1] + cost[s2[j]];
        } else {
          dp[i][j] = cost[s2[j]];
        }
      }
    }
  }

  int res = suffix[0];
  for(int i = 0; i < n; i++) {
    res = min(res, dp[i][0]);
  }

  cout << res << endl;
  return 0;
}
