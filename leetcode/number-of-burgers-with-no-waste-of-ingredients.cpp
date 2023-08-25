// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> numOfBurgers(int a1, int a0) {
    if (a1 - 2 * a0 < 0 || (a1 - 2 * a0) & 1) {
      return {};
    }
    int x = (a1 - 2 * a0) >> 1;
    if (a0 - x < 0) {
      return {};
    }
    return {x, a0 - x};
  }
};
