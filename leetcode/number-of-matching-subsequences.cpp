// https://leetcode.com/problems/number-of-matching-subsequences/
#include "bits/stdc++.h"
using namespace std;

vector<vector<pair<int, int>>> v(26, vector<pair<int, int>>(5000));
vector<int> u;
vector<pair<int, int>> temp(5000);

class Solution {
public:
  int numMatchingSubseq(string &s, vector<string> &words) {
    u = vector<int>(26, 0);
    const int m = words.size();
    char ch;
    for (int i = 0; i < m; i++) {
      ch = words[i][0];
      v[ch - 'a'][u[ch - 'a']] = {i, 0};
      u[ch - 'a']++;
    }
    int removed = 0;
    int index_1;
    int index_2;
    int n, z = 0;
    for (auto &ch : s) {
      for (int i = 0; i < u[ch - 'a']; i++) {
        index_1 = v[ch - 'a'][i].first;
        index_2 = v[ch - 'a'][i].second;
        n = words[index_1].length();
        if (index_2 + 1 < n) {
          char ch2 = words[index_1][index_2 + 1];
          if (ch == ch2) {
            temp[z] = {index_1, index_2 + 1};
            z++;
          } else {
            v[ch2 - 'a'][u[ch2 - 'a']] = {index_1, index_2 + 1};
            u[ch2 - 'a']++;
          }
        } else {
          removed++;
        }
      }
      u[ch - 'a'] = 0;
      for (int i = 0; i < z; i++) {
        v[ch - 'a'][u[ch - 'a']] = temp[i];
        u[ch - 'a']++;
      }
      z = 0;
    }
    return removed;
  }
};
