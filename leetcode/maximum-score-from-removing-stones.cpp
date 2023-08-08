// https://leetcode.com/problems/maximum-score-from-removing-stones/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
  }

  int maximumScore(int a, int b, int c) {
    if (a <= b && a <= c) {
    } else if (b <= a && b <= c) {
      swap(a, b);
    } else {
      swap(a, c);
    }
    if (b && c) {
      return 1 + maximumScore(a, b - 1, c - 1);
    }
    return 0;
  }
};
