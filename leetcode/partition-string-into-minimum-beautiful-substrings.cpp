// https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/
#include "bits/stdc++.h"
using namespace std;

class Solution {
  const vector<string> p = {
      "1",          "101",          "11001",          "1111101",
      "1001110001", "110000110101", "11110100001001", "10011000100101101"};

public:
  int minimumBeautifulSubstrings(string &s) {
    return minimumBeautifulSubstrings(s, 0);
  }
  int minimumBeautifulSubstrings(string &s, int i) {
    int n = s.length();
    if (i >= n) {
      return 0;
    }
    int res = INT_MAX;
    for (auto &x : p) {
      int j = x.length();
      if (x == s.substr(i, j)) {
        int sub = minimumBeautifulSubstrings(s, i + j);
        if (sub != -1) {
          res = min(res, 1 + sub);
        }
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};
