// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxRepOpt1(string &s) {
    vector<vector<vector<int>>> arr(26);
    int n = s.length(), d, d2, l, i, j;
    for (i = 0, j = 0; i < n; i++) {
      if (s[i] != s[j]) {
        arr[s[j] - 'a'].push_back({j, i});
        j = i;
      }
    }
    arr[s[j] - 'a'].push_back({j, i});
    int ans = 1;
    for (int i = 0; i < 26; i++) {
      l = arr[i].size();
      if (l == 0) {
        continue;
      }
      d = arr[i][0][1] - arr[i][0][0];
      d2 = d;
      ans = max(ans, d);
      if (l == 1) {
        continue;
      }
      for (int k = 1; k < l; k++) {
        d = arr[i][k][1] - arr[i][k][0];
        d2 = max(d, d2);
        ans = max(ans, d);
        if (arr[i][k - 1][1] + 1 == arr[i][k][0]) {
          d = arr[i][k][1] - arr[i][k - 1][0];
          if (l == 2) {
            ans = max(ans, d - 1);
          } else { // > 2
            ans = max(ans, d);
          }
        }
      }
      ans = max(ans, d2 + 1);
    }
    return ans;
  }
};
