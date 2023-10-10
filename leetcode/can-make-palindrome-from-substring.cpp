// https://leetcode.com/problems/can-make-palindrome-from-substring/
#include "bits/stdc++.h"
using namespace std;

int prefix[int(1e5)][26];
class Solution {
public:
  vector<bool> canMakePaliQueries(string &s, vector<vector<int>> &queries) {
    int n = s.length();
    int m = queries.size();
    vector<bool> res(m);
    int idx = 0, start, end, k, c;
    for (int i = 0; i < 26; i++) {
      prefix[0][i] = 0;
    }
    prefix[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 26; j++) {
        prefix[i][j] = prefix[i - 1][j];
      }
      prefix[i][s[i] - 'a']++;
    }
    for (auto &q : queries) {
      start = q[0];
      end = q[1];
      k = q[2];
      c = 0;
      for (int i = 0; i < 26; i++) {
        int diff = prefix[end][i] - (start > 0 ? prefix[start - 1][i] : 0);
        if (diff & 1) {
          c++;
        }
      }
      if (c & 1) {
        c--;
      }
      res[idx++] = k >= c / 2;
    }
    return res;
  }
};
