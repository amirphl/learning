// https://leetcode.com/problems/boats-to-save-people/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &p, int limit) {
    sort(p.begin(), p.end());
    int n = p.size();
    int count = 0;
    for (int i = 0, j = n - 1; i <= j;) {
      if (p[i] + p[j] <= limit) {
        i++;
        j--;
      } else {
        j--;
      }
      count++;
    }
    return count;
  }
};
