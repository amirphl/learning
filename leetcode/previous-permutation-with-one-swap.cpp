// https://leetcode.com/problems/previous-permutation-with-one-swap/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &arr) {
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > arr[i + 1]) {
        int pos = bs(arr, i + 1, n - 1, arr[i]);
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
        break;
      }
    }
    return arr;
  }

  int bs(const vector<int> &arr, const int low, const int high,
         const int elem) {
    while (low <= high) {
      if (low == high) {
        if (arr[low] < elem) {
          return low;
        }
        return -1;
      }

      if (low + 1 == high) {
        if (arr[low] == arr[high] && arr[low] < elem) {
          return low;
        }
        if (arr[high] < elem) {
          return high;
        }
        if (arr[low] < elem) {
          return low;
        }
        return -1;
      }

      int mid = low + ((high - low) >> 1);

      if (arr[mid] < elem) {
        int pos = bs(arr, mid, high, elem);
        if (arr[mid] == arr[pos]) {
          return bs(arr, low, mid, elem);
        }
        return pos;
      } else {
        return bs(arr, low, mid - 1, elem);
      }
    }
    return -1;
  }
};
