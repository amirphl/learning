// https://leetcode.com/problems/single-element-in-a-sorted-array/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    if (n == 1) {
      return nums[0];
    }
    while (low <= high) {
      if (low == high) {
        return nums[low];
      }
      int mid = (low + high) >> 1;
      if (mid == low && nums[low] != nums[low + 1]) {
        return nums[low];
      }
      if (mid == high && nums[high - 1] != nums[high]) {
        return nums[high];
      }
      if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
        return nums[mid];
      }
      if (nums[mid - 1] == nums[mid]) {
        int elems = mid - low + 1;
        if (elems % 2 == 0) {
          low = mid + 1;
        } else {
          high = mid;
        }
      } else {
        int elems = high - mid + 1;
        if (elems % 2 == 0) {
          high = mid - 1;
        } else {
          low = mid;
        }
      }
    }
    return -1;
  }
};
