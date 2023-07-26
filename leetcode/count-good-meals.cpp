// https://leetcode.com/problems/count-good-meals/
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int countPairs(vector<int> &d) {
    unordered_map<int, int> m;
    int x, res = 0;

    for (auto &elem : d) {
      x = 1;

      for (int i = 0; i < 22; i++) {
        int y = x - elem;

        if (y > -1 && m.find(y) != m.end()) {
          res = (res + m[y]) % (int)(1e9 + 7);
        }

        x = x << 1;
      }

      if (m.find(elem) == m.end()) {
        m[elem] = 0;
      }

      m[elem]++;
    }
    return res;
  }

  // TLE
  int countPairs2(vector<int> &d) {
    int res = 0;
    int n = d.size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        uint32_t s = d[i] + d[j];
        int num_ones = 0;

        while (s != 0) {
          if (s % 2) {
            num_ones++;
          }
          if (num_ones > 1) {
            break;
          }
          s = s >> 1;
        }

        if (num_ones == 1) {
          res++;
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> d{1, 1, 1, 3, 3, 3, 7};
  Solution sol;
  cout << sol.countPairs(d) << endl;
}
