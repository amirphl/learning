// https://leetcode.com/problems/powerful-integers/
#include "bits/stdc++.h"
using namespace std;

class Solution {
  int MAX = 1e6;

public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    int n = x == 1 ? 1 : log(MAX) / log(x) + 1;
    int m = y == 1 ? 1 : log(MAX) / log(y) + 1;

    uint64_t t[n];
    uint64_t v[m];

    uint64_t a = 1;
    for (int i = 0; i < n; i++) {
      t[i] = a;
      a *= x;
    }

    a = 1;
    for (int i = 0; i < m; i++) {
      v[i] = a;
      a *= y;
    }

    vector<int> res;
    unordered_set<uint64_t> s;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        uint64_t sum = t[i] + v[j];
        if (sum <= bound) {
          if (s.find(sum) != s.end()) {
            continue;
          }
          res.push_back(sum);
          s.insert(sum);
        } else {
          break;
        }
      }
    }

    return res;
  }
};
