// https://leetcode.com/problems/minimum-sum-of-squared-difference/
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  const int MAX_DIFF = (int)1e5 + 1;

  long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1,
                             int k2) {
    int n = nums1.size();
    int freq[MAX_DIFF];
    memset(freq, 0, sizeof(freq));
    uint64_t res = 0;

    for (int i = 0; i < n; i++) {
      int diff = abs(nums1[i] - nums2[i]);
      freq[diff]++;
    }

    uint64_t k = k1 + k2;
    int left = 0, right = MAX_DIFF - 1;

    while (left <= right) {
      uint64_t sum = 0, c = 0;

      if (left == right) {
        int j;

        for (int i = 0; i < MAX_DIFF; i++) {
          j = min(left, i);
          res += (uint64_t)freq[i] * j * j;

          if (left <= i) {
            c += freq[i];
            k -= freq[i] * (i - left);
          }
        }

        if (k > 0 && left > 0) {
          if (c >= k) {
            res = res - k * left * left + k * (left - 1) * (left - 1);
          } else {
            cout << "PANIC\n";
          }
        }

        return res;
      }

      int mid = (left + right) >> 1;

      for (int i = MAX_DIFF - 1; i > mid; i--) {
        c += freq[i];
        sum += (uint64_t)freq[i] * (i - mid);

        if (sum > k) {
          break;
        }
      }

      if (sum > k) {
        left = mid + 1;
      } else if (sum == k) {
        for (int i = 0; i <= mid; i++) {
          res += (uint64_t)freq[i] * i * i;
        }

        res += c * mid * mid;

        return res;
      } else {
        right = mid;
      }
    }

    return -1;
  }
};

int main() {
  Solution sol;
  return 0;
}
