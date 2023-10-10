// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
#include "bits/stdc++.h"
using namespace std;

int par[26];
int smallest[26];
class Solution {
public:
  string smallestEquivalentString(string &s1, string &s2, string &baseStr) {
    memset(par, -1, sizeof(par));
    memset(smallest, -1, sizeof(smallest));
    int n = s1.length();
    int m = baseStr.length();
    for (int i = 0; i < n; i++) {
      int p1 = parent(s1[i] - 'a');
      int p2 = parent(s2[i] - 'a');
      if (p1 != p2) {
        par[p1] = p2;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (smallest[parent(i)] == -1) {
        smallest[par[i]] = i;
      } else {
        smallest[par[i]] = min(smallest[par[i]], i);
      }
    }
    for (int i = 0; i < m; i++) {
      baseStr[i] = smallest[par[baseStr[i] - 'a']] + 'a';
    }
    return baseStr;
  }

  int parent(int i) {
    if (par[i] == -1 || par[i] == i) {
      return par[i] = i;
    }
    return par[i] = parent(par[i]);
  }
};
