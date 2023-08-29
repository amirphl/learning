// https://leetcode.com/problems/decoded-string-at-index/
#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> v(101);
vector<uint64_t> z(101);
class Solution {
public:
  string decodeAtIndex(string &s, int k) {
    int n = s.length();
    uint64_t curr_size = 0;
    int idx = 0;
    for (int i = 0; i < n;) {
      int j = i;
      for (; j < n && 'a' <= s[j] && s[j] <= 'z'; j++, curr_size++)
        ;
      int d = j == n ? 1 : s[j] - '0';
      v[idx] = {i, j, d};
      z[idx] = curr_size;
      idx++;
      // cout << i << " " << j << " " << curr_size << " " << d << endl;
      if (k <= curr_size * d) {
        k--;
        idx--;
        for (; idx >= 0; idx--) {
          int p = v[idx][0];
          int q = v[idx][1];
          int t = v[idx][2];
          uint64_t r = z[idx];
          // cout << i << " " << j << " " << curr_size << " " << d << " " << k
          // << endl;
          k = k % r;
          uint64_t rem = r - (q - p);
          if (k < rem) {
            continue;
          }
          return string(1, s[p + k - rem]);
        }
        return "A";
      }
      curr_size *= d;
      i = j + 1;
    }
    return "A";
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
