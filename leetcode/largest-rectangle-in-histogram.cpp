// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include "bits/stdc++.h"
using namespace std;

const int N = 200000;
int arr[N];

class Solution {
public:
  int largestRectangleArea(vector<int> &nums) {
    int n = nums.size();
    arr[0] = -1;
    arr[1] = n;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] < nums[i]) {
        arr[2 * i] = i - 1;
      } else {
        int j = arr[2 * (i - 1)];
        while (j != -1 && nums[j] >= nums[i]) {
          j = arr[2 * j];
        }
        arr[2 * i] = j;
      }
      int k = n - 1 - i;
      if (nums[k] > nums[k + 1]) {
        arr[2 * i + 1] = k + 1;
      } else {
        int j = arr[2 * (i - 1) + 1];
        while (j != n && nums[j] >= nums[k]) {
          j = arr[2 * (n - 1 - j) + 1];
        }
        arr[2 * i + 1] = j;
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = max(res, nums[i] * ((arr[2 * (n - i - 1) + 1] - 1) -
                                (arr[2 * i] + 1) + 1));
    }
    return res;
  }
};
