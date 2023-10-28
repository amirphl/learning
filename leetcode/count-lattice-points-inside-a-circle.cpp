// https://leetcode.com/problems/count-lattice-points-inside-a-circle/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int countLatticePoints(vector<vector<int>> &circles) {
    unordered_set<int64_t> unique;
    int x, y, r;
    int a, b, c;
    int cnt = 0;
    int64_t point;
    for (auto &circle : circles) {
      x = circle[0], y = circle[1], r = circle[2];
      c = r * r;
      for (int i = x - r; i <= x + r; i++) {
        a = abs(i - x);
        a *= a;
        for (int j = y; j <= y + r; j++) {
          b = abs(j - y);
          b *= b;
          if (a + b <= c) {
            point = to_point(i, j);
            if (unique.find(point) == unique.end()) {
              unique.insert(point);
              cnt++;
            }
            point = to_point(i, y - (j - y));
            if (unique.find(point) == unique.end()) {
              unique.insert(point);
              cnt++;
            }
          } else {
            break;
          }
        }
      }
    }
    return cnt;
  }

  int64_t to_point(int x, int y) {
    int64_t p = x;
    p = p << 32;
    p += y;
    return p;
  }
};
