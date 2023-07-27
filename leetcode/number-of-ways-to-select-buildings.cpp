// https://leetcode.com/problems/number-of-ways-to-select-buildings/
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  long long numberOfWays(string s) {
    int n = s.length();

    if (n < 3) {
      return 0;
    }

    uint64_t ones[n];
    uint64_t zeros[n];
    uint64_t zo[n];
    uint64_t oz[n];

    ones[n - 1] = s[n - 1] == '1';
    zeros[n - 1] = s[n - 1] == '0';
    zo[n - 1] = 0;
    oz[n - 1] = 0;
    zo[n - 2] = s[n - 2] == '0' && s[n - 1] == '1';
    oz[n - 2] = s[n - 2] == '1' && s[n - 1] == '0';

    uint64_t res1 = 0, res2 = 0;

    for (int i = n - 2; i >= 0; i--) {
      ones[i] = ones[i + 1] + (s[i] == '1');
      zeros[i] = zeros[i + 1] + (s[i] == '0');

      if (i < n - 2) {
        zo[i] = oz[i] = 0;
        zo[i] += zo[i + 1];
        oz[i] += oz[i + 1];

        if (s[i] == '0') {
          zo[i] += ones[i + 1];
          res1 += oz[i + 1];
        } else {
          oz[i] += zeros[i + 1];
          res2 += zo[i + 1];
        }
      }
    }

    return res1 + res2;
  }
};

int main() {
  Solution sol;
  cout << sol.numberOfWays("0101010110111010001010011101010") << endl;
  return 0;
}
