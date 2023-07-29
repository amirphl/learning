// https://leetcode.com/problems/mice-and-cheese/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // greedy
  // Not works for
  // reward1 = [5, 30, 8, 18, 19, 28, 3, 11, 14, 25, 30, 16, 27, 30, 9, 7, 20,
  // 28, 29, 16, 30, 16, 6, 8, 13, 10, 16, 28, 17, 8, 5, 9, 7, 11, 7, 28, 9, 20,
  // 27, 8, 19, 14, 18, 29, 6, 26, 16, 16, 3, 13, 21, 25, 30, 30, 18, 23, 3, 17,
  // 15, 1, 9, 16, 10, 19, 29, 6, 7, 30, 24, 22, 20, 21, 29, 20, 25, 2, 18, 13,
  // 2, 15, 7, 3, 9, 2, 30, 3, 23, 30, 7, 30, 23, 26, 8, 24, 30, 23, 10, 5, 2,
  // 22]
  // reward2 = [12, 10, 2, 24, 5, 4, 30, 29, 14, 1, 5, 5, 14, 3, 13, 22, 4,
  // 16, 26, 9, 26, 5, 13, 5, 23, 2, 17, 4, 24, 30, 30, 2, 22, 6, 8, 16, 26, 27,
  // 11, 26, 13, 30, 18, 5, 29, 11, 28, 26, 30, 24, 12, 21, 29, 21, 5, 7, 22,
  // 21, 29, 27, 18, 23, 12, 18, 16, 28, 8, 12, 22, 11, 15, 26, 17, 14, 29, 12,
  // 7, 15, 7, 11, 20, 12, 17, 2, 20, 16, 7, 8, 7, 1, 26, 12, 19, 12, 7, 29, 20,
  // 23, 6, 2]
  // k = 2
  int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    int n = reward1.size();
    vector<pair<double, vector<int>>> arr(n);

    for (int i = 0; i < n; i++) {
      double a = reward1[i] * 1.0 / reward2[i];
      double b = reward2[i] * 1.0 / reward1[i];

      if (a > b) {
        arr[i] = {a, {1, i}};
      } else {
        arr[i] = {b, {2, i}};
      }
    }

    sort(arr.begin(), arr.end(), greater<pair<double, vector<int>>>());

    int res = 0;

    for (int i = 0; i < n; i++) {
      auto x = arr[i].second;
      if (x[0] == 1) {
        if (k > 0) {
          k--;
          res += reward1[x[1]];
        } else {
          res += reward2[x[1]];
        }
      } else {
        if (n - i > k) {
          res += reward2[x[1]];
        } else {
          k--;
          res += reward1[x[1]];
        }
      }
    }

    return res;
  }
};
