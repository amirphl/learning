// https://leetcode.com/problems/avoid-flood-in-the-city/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    int n = rains.size();
    vector<int> res(n, 1);
    set<int> t;
    unordered_map<int, int> s;
    for (int i = 0; i < n; i++) {
      int r = rains[i];
      if (r) {
        res[i] = -1;
        if (s.find(r) == s.end()) {
          s[r] = i;
        } else {
          int d = s[r];
          auto it = t.lower_bound(d);
          if (it == t.end()) {
            return {};
          }
          res[*it] = r;
          s[r] = i;
          t.erase(it);
        }
      } else {
        t.insert(i);
      }
    }
    return res;
  }
};
