#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int two = 0;
    int five = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      while (j && j % 5 == 0) {
        j /= 5;
        five++;
      }
      j = i;
      while (j && j % 2 == 0) {
        j /= 2;
        two++;
      }
    }
    return min(two, five);
  }
};
