// https://leetcode.com/problems/sliding-window-median/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    int m = n - k + 1;

    if (k == 1) {
      vector<double> res(n);
      for (int i = 0; i < n; i++) {
        res[i] = nums[i];
      }
      return res;
    }

    // multiset<int> s1(nums.begin(), nums.begin() + k);
    // multiset<int> s2;
    // for (int i = 0; i < k / 2; i++) {
    //   auto it = s1.rbegin();
    //   s2.insert(*it);
    //   s1.erase(s1.lower_bound(*it));
    // }
    vector<int> v(nums.begin(), nums.begin() + k);
    nth_element(v.begin(), v.begin() + (k - 1) / 2, v.end());
    partition(v.begin(), v.end(),
              [v, k](int i) { return i <= v[(k - 1) / 2]; });
    vector<double> res(m);
    multiset<int> s1(v.begin(), v.begin() + (k + 1) / 2);
    multiset<int> s2(v.begin() + (k + 1) / 2, v.end());

    int64_t s1_max, s2_min;
    const int MAX_S1_S2_DIFF = (k & 1) ? 1 : 0;
    double median;

    if (k & 1) {
      res[0] = *(s1.rbegin());
    } else {
      s1_max = *(s1.rbegin());
      s2_min = *(s2.begin());
      median = s1_max + (s2_min - s1_max) / 2.0;
      res[0] = median;
    }

    for (int i = 0, j = k; i < m - 1; i++, j++) {
      s1_max = *(s1.rbegin());

      if (nums[i] <= s1_max) {
        s1.erase(s1.lower_bound(nums[i]));
      } else {
        s2.erase(s2.lower_bound(nums[i]));
      }

      if (s2.empty()) {
        s1.insert(nums[j]);
      } else {
        s2_min = *(s2.begin());

        if (s2_min <= nums[j]) {
          s2.insert(nums[j]);
        } else {
          s1.insert(nums[j]);
        }
      }

      int len1 = s1.size();
      int len2 = s2.size();

      while (len1 - len2 > MAX_S1_S2_DIFF) {
        auto it = s1.rbegin();
        s2.insert(*it);
        s1.erase(s1.lower_bound(*it));
        len1 = s1.size();
        len2 = s2.size();
      }

      len1 = s1.size();
      len2 = s2.size();

      while (len2 - len1 > -MAX_S1_S2_DIFF) {
        auto it = s2.begin();
        s1.insert(*it);
        s2.erase(s2.lower_bound(*it));
        len1 = s1.size();
        len2 = s2.size();
      }

      s1_max = *(s1.rbegin());
      s2_min = *(s2.begin());

      if (k & 1) {
        res[i + 1] = s1_max;
      } else {
        double x = s1_max + (s2_min - s1_max) / 2.0;
        res[i + 1] = x;
      }
    }

    return res;
  }
};

int main() {
  vector<int> nums{3, 1, 4, 2, 2, 3, 1, 4, 2};
  int k = 4;
  Solution sol;
  vector<double> res = sol.medianSlidingWindow(nums, k);
  for (auto &it : res) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
