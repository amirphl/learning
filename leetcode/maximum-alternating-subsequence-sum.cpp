// https://leetcode.com/problems/maximum-alternating-subsequence-sum/
#include "bits/stdc++.h"
using namespace std;

template <typename T>
void sort_indexes(const vector<T> &v, vector<size_t> &idx) {
  // initialize original index locations

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values
  stable_sort(idx.begin(), idx.end(),
              [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });
  return;
};

const int N = int(1e5 + 1);
bool mark[N];
class Solution {
public:
  // THIS DOESN'T WORK.
  long long maxAlternatingSum(vector<int> &nums) {
    memset(mark, 0, sizeof(mark));
    int n = nums.size();
    vector<size_t> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort_indexes(nums, idx);
    for (int i = n - 1; i >= 0; i--) {
      if (mark[idx[i] + 1] == 0 && (idx[i] == 0 || mark[idx[i] - 1] == 0)) {
        mark[idx[i]] = 1;
      }
    }
    // for (int i = 0; i < int(1e5 + 1); i++) {
    //   cout << mark[i] << " ";
    // }
    int64_t res = 0;
    int temp = 0;
    for (int i = 0; i < n; i++) {
      if (mark[i]) {
        res = res + nums[i] - temp;
        temp = INT_MAX;
      } else {
        temp = min(temp, nums[i]);
      }
    }
    return res;
  }
};
