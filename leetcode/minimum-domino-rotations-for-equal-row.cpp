// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    const int n = tops.size();
    unordered_map<int, int> m;
    int num, freq = 0;
    for (int i = 0; i < n; i++) {
      bool f = 0;
      m[tops[i]]++;
      if (m[tops[i]] > freq) {
        num = tops[i];
        freq = m[num];
      }
      if (tops[i] != bottoms[i]) {
        m[bottoms[i]]++;
        if (m[bottoms[i]] > freq) {
          num = bottoms[i];
          freq = m[num];
        }
      }
    }
    if (freq < n) {
      return -1;
    }
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
      if (tops[i] != num) {
        cnt++;
      }
      if (bottoms[i] != num) {
        cnt2++;
      }
    }
    return min({cnt, n - cnt, cnt2, n - cnt2});
  }
};
