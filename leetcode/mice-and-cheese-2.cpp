// https://leetcode.com/problems/mice-and-cheese/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    int n = reward1.size();
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
      int a = reward1[i] - reward2[i];
      int b = reward2[i] - reward1[i];

      if (a > b) {
        arr[i] = {a, 1, i};
      } else {
        arr[i] = {b, 2, i};
      }
    }

    sort(arr.begin(), arr.end(), greater<vector<int>>());

    int res = 0;

    for (int i = 0; i < n; i++) {
      int x = arr[i][1];
      int y = arr[i][2];

      if (x == 1) {
        if (k > 0) {
          k--;
          res += reward1[y];
        } else {
          res += reward2[y];
        }
      } else {
        if (n - i > k) {
          res += reward2[y];
        } else {
          k--;
          res += reward1[y];
        }
      }
    }

    return res;
  }
};
