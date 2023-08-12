// https://leetcode.com/problems/incremental-memory-leak/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> memLeak(int memory1, int memory2) {
    int i = 1;
    while (memory1 || memory2) {
      if (memory1 == memory2) {
        if (i <= memory1) {
          memory1 -= i;
        } else {
          return {i, memory1, memory2};
        }
      } else if (memory1 > memory2) {
        if (i <= memory1) {
          memory1 -= i;
        } else {
          return {i, memory1, memory2};
        }
      } else {
        if (i <= memory2) {
          memory2 -= i;
        } else {
          return {i, memory1, memory2};
        }
      }
      i++;
    }
    return {i, memory1, memory2};
  }
};
