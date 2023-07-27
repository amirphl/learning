// https://leetcode.com/problems/number-of-ways-to-select-buildings/
#include "bits/stdc++.h"

using namespace std;

// TODO This code doesn't work. Why?

class Solution {
public:
  long long numberOfWays(string s) {
    int n = s.length();

    if (n < 3) {
      return 0;
    }

    uint64_t ones;
    uint64_t zeros;
    uint64_t zo;
    uint64_t oz;

    ones = s[n - 1] == '1';
    zeros = s[n - 1] == '0';
    zo = s[n - 2] == '0' && s[n - 1] == '1';
    oz = s[n - 2] == '1' && s[n - 1] == '0';

    uint64_t res1 = 0, res2 = 0;

    for (int i = n - 2; i >= 0; i--) {
      int n_ones = ones + (s[i] == '1');
      int n_zeros = zeros + (s[i] == '0');

      if (i < n - 2) {
        int n_zo = zo;
        int n_oz = oz;

        if (s[i] == '0') {
          n_zo += ones;
          res1 += oz;
        } else {
          n_oz += zeros;
          res2 += zo;
        }

        zo = n_zo;
        oz = n_oz;
      }

      ones = n_ones;
      zeros = n_zeros;
    }

    return res1 + res2;
  }
};

int main() {
  Solution sol;
  cout << sol.numberOfWays("0101010110111010001010011101010") << endl;
  return 0;
}
