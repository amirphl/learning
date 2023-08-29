// https://leetcode.com/problems/decoded-string-at-index/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  string decodeAtIndex(string &s, int k) {
    int n = s.length();
    uint64_t curr_size = 0;
    vector<vector<uint64_t>> v;
    for (int i = 0; i < n;) {
      int j = i;
      for (; j < n && 'a' <= s[j] && s[j] <= 'z'; j++, curr_size++)
        ;
      int d = j == n ? 1 : s[j] - '0';
      v.push_back({(uint64_t)i, (uint64_t)j, curr_size, (uint64_t)d});
      // cout << i << " " << j << " " << curr_size << " " << d << endl;
      if (k <= curr_size * d) {
        return string(1, find(s, v, k - 1, v.size() - 1));
      }
      curr_size *= d;
      i = j + 1;
    }
    return "A";
  }

  char find(string &s, vector<vector<uint64_t>> &v, int k, int index) {
    int i = v[index][0];
    int j = v[index][1];
    uint64_t curr_size = v[index][2];
    int d = v[index][3];
    // cout << i << " " << j << " " << curr_size << " " << d << " " << k <<
    // endl;
    k = k % curr_size;
    int rem = curr_size - (j - i);
    if (k < rem) {
      return find(s, v, k, index - 1);
    }
    return s[i + k - rem];
  }
};

int main() {
  Solution sol;
  // string s = "a2345678999999999999999";
  // cout << sol.decodeAtIndex(s, 56247680) << endl;

  string s = "leet2code3";
  cout << sol.decodeAtIndex(s, 10) << endl;
  return 0;
}
