// https://leetcode.com/problems/incremental-memory-leak/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
  }
  vector<int> memLeak(int memory1, int memory2) {
    int64_t i = 1;
    while (memory1 || memory2) {
      int swapped = 0;
      if (memory1 < memory2) {
        swap(memory1, memory2);
        swapped = 1;
      }
      int64_t m = memory1 - memory2;
      int64_t x = i - (2 * m) - (i * i);
      int64_t n = i;
      if (1 - 4 * x >= 0) {
        n = (int64_t)((sqrt(1 - 4 * x) - 1) / 2);
      }
      int64_t sum = (n * (n + 1) - i * (i - 1)) / 2;
      if (i < n && 0 < sum) {
        memory1 -= sum;
        i = n + 1;
      } else {
        if (i <= memory1) {
          memory1 -= i;
          i++;
        } else {
          if (swapped) {
            swap(memory1, memory2);
          }
          return {(int)i, memory1, memory2};
        }
      }
      if (swapped) {
        swap(memory1, memory2);
      }
    }
    return {(int)i, memory1, memory2};
  }
};
