// https://leetcode.com/problems/k-concatenation-maximum-sum/
#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
  int kConcatenationMaxSum(vector<int> &arr, int k) {
    const int n = arr.size();
    int64_t curr_sum = 0;
    int64_t total_sum = 0, max_pre_sum = 0, max_suf_sum = 0;
    int64_t acc = 0;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      total_sum += arr[i];
      max_pre_sum = max(max_pre_sum, total_sum);
      curr_sum += arr[i];
      if (curr_sum < 0) {
        curr_sum = 0;
      } else {
        ans = max(ans, curr_sum);
      }
    }
    total_sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      total_sum += arr[i];
      max_suf_sum = max(max_suf_sum, total_sum);
    }
    if (k > 1 && max_pre_sum >= 0 && max_suf_sum >= 0) {
      acc = 0;
      if (total_sum < 0) {
        ans = max(ans, max_pre_sum + max_suf_sum);
      } else {
        bool flag = 0;
        acc = 0;
        for (int i = 0; i < k - 2; i++) {
          if (acc > ans) {
            flag = 1;
          }
          if (flag) {
            acc = acc % MOD;
          }
          acc = acc + total_sum;
        }
        acc += max_pre_sum + max_suf_sum;
        if (acc > ans) {
          flag = 1;
        }
        if (flag) {
          acc = acc % MOD;
          ans = acc;
        }
      }
    }
    return ans % MOD;
  }
};
