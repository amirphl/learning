// https://leetcode.com/problems/find-good-days-to-rob-the-bank/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> goodDaysToRobBank(vector<int> &sec, const int time) {
    int n = sec.size();
    if (time == 0) {
      vector<int> res(n);
      for (int i = 0; i < n; i++) {
        res[i] = i;
      }
      return res;
    }
    int dec[n];
    int inc[n];
    dec[0] = inc[n - 1] = 0;
    for (int i = 1, j = n - 2; i < n; i++, j--) {
      if (sec[i - 1] >= sec[i]) {
        dec[i] = dec[i - 1] + 1;
      } else {
        dec[i] = 0;
      }
      if (sec[j] <= sec[j + 1]) {
        inc[j] = inc[j + 1] + 1;
      } else {
        inc[j] = 0;
      }
    }
    vector<int> res;
    for (int i = time; i < n - time; i++) {
      if (time <= dec[i] && time <= inc[i]) {
        res.push_back(i);
      }
    }
    return res;
  }
};
