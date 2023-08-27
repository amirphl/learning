// https://leetcode.com/problems/count-number-of-teams/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int numTeams(vector<int> &rating) {
    int n = rating.size();
    int less[n];
    int greater[n];
    less[0] = 0;
    greater[n - 1] = 0;

    set<int> s;
    set<int> s2;
    s.insert(rating[0]);
    s2.insert(rating[n - 1]);

    for (int i = 1; i < n; i++) {
      int dist = distance(s.begin(), s.lower_bound(rating[i]));
      less[i] = dist;
      s.insert(rating[i]);
      dist = distance(s2.lower_bound(rating[n - i - 1]), s2.end());
      greater[n - i - 1] = dist;
      s2.insert(rating[n - i - 1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += less[i] * greater[i] + (i - less[i]) * (n - i - 1 - greater[i]);
    }

    return ans;
  }
};
