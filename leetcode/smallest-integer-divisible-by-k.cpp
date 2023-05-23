// https://leetcode.com/problems/smallest-integer-divisible-by-k/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
      if (k % 2 == 0 || k % 5 == 0) {
        return -1;
      }
      int i = 0;
      bool arr[k];
      memset(arr, 0, sizeof(arr));
      int prev = 0;
      for(; i < k; i++) {
        int rem = (10 * prev + 1) % k;
        if (rem == 0) {
          break;
        }
        if (arr[rem]) {
          return -1;
        } else {
          arr[rem] = 1;
        }
        prev = rem;
      }
      return i;
    }
};
