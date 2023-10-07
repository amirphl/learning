#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int two = 0;
    int five = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      int base = 5;
      int count = 1;
      while (j && j % base == 0) {
        j /= base;
        five += count;
        base *= base;
        count *= 2;
        if (j && j % 5 == 0 && j % base != 0) {
          base = 5;
          count = 1;
        }
      }
      base = 2;
      count = 1;
      while (j && j % base == 0) {
        j /= base;
        two += count;
        base *= base;
        count *= 2;
        if (j && j % 2 == 0 && j % base != 0) {
          base = 2;
          count = 1;
        }
      }
    }
    return min(two, five);
  }
};
