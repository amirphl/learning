// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
#include "bits/stdc++.h"
using namespace std;

vector<char> v;
class Solution {
public:
  bool isValid(string &s) {
    if (!s.empty() && s[0] != 'a') {
      return 0;
    }
    v.clear();
    int n = s.length();
    int j;
    for (int i = 0; i < n; i++) {
      if (s.substr(i, 3) == "abc") {
        i += 2;
      } else {
        v.push_back(s[i]);
        j = v.size() - 1;
        while (j >= 2 && v[j] == 'c' && v[j - 1] == 'b' && v[j - 2] == 'a') {
          v.pop_back();
          v.pop_back();
          v.pop_back();
          j = v.size() - 1;
        }
      }
    }
    j = v.size() - 1;
    while (j >= 2 && v[j] == 'c' && v[j - 1] == 'b' && v[j - 2] == 'a') {
      v.pop_back();
      v.pop_back();
      v.pop_back();
      j = v.size() - 1;
    }
    return v.empty();
  }
};
