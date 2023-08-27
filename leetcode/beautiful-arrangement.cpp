// https://leetcode.com/problems/beautiful-arrangement/
#include "bits/stdc++.h"
using namespace std;

class Solution {
  int n;
  unordered_set<int> visited;

public:
  int countArrangement(int n) {
    this->n = n;
    int ans = 0;
    rec(1, ans);
    return ans;
  }

  void rec(int i, int &ans) {
    if (i == n + 1) {
      ans++;
      return;
    }
    for (int j = 1; j <= n; j++) {
      if (visited.find(j) != visited.end()) {
        continue;
      }
      if (j % i == 0 || i % j == 0) {
        visited.insert(j);
        rec(i + 1, ans);
        visited.erase(j);
      }
    }
    return;
  }
};
