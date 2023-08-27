// https://leetcode.com/problems/best-sightseeing-pair/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int n = values.size();
    int t = values[n - 1] - (n - 1);
    int ans = INT_MIN;
    for (int i = n - 2; i >= 0; i--) {
      ans = max(ans, values[i] + i + t);
      t = max(t, values[i] - i);
    }
    return ans;
  }
};
