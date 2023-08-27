// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int diff) {
    int n = arr.size();
    unordered_map<int, int> m;
    m[arr[0]] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
      int t = arr[i] - diff;
      int x = m[t] + 1;
      m[arr[i]] = max(m[arr[i]], x);
      ans = max(ans, m[arr[i]]);
    }
    return ans;
  }
};
