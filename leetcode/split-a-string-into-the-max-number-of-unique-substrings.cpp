// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxUniqueSplit(string &s) {
    unordered_set<string> visited;
    return rec(s, visited);
  }

  int rec(string &s, unordered_set<string> &visited) {
    int n = s.length();
    int ans = (visited.find(s) == visited.end()) ? 1 : 0;
    for (int i = 1; i < n; i++) {
      string sub = s.substr(0, i);
      if (visited.find(sub) != visited.end()) {
        continue;
      }
      visited.insert(sub);
      string rem = s.substr(i, n - i);
      ans = max(ans, 1 + rec(rem, visited));
      visited.erase(sub);
    }
    return ans;
  }
};
