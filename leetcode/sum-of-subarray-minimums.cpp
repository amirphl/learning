// https://leetcode.com/problems/sum-of-subarray-minimums/description/
#include "bits/stdc++.h"
using namespace std;

int prefix[30000];
int suffix[30000];
const int MOD = 1e9 + 7;

class Solution {
public:
  int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    stack<int> s, r;
    for (int i = 0; i < n; i++) {
      while (!s.empty() && arr[s.top()] > arr[i]) {
        s.pop();
      }
      prefix[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
      while (!r.empty() && arr[r.top()] >= arr[i]) {
        r.pop();
      }
      suffix[i] = r.empty() ? n : r.top();
      r.push(i);
    }
    uint64_t cnt = 0, len, u, v;
    for (int i = 0; i < n; i++) {
      // cout << suffix[i] << " " << prefix[i] << " " << arr[i] << endl;
      len = suffix[i] - prefix[i] - 1;
      len = len * (len + 1) / 2;
      u = i - prefix[i] - 1;
      u = u * (u + 1) / 2;
      v = suffix[i] - i - 1;
      v = v * (v + 1) / 2;
      cnt = (cnt + arr[i] * (len - u - v)) % MOD;
    }
    return cnt;
  }
};
