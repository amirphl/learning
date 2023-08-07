// https://leetcode.com/problems/remove-covered-intervals/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &x, const vector<int> &y) {
           return x[0] < y[0] || x[0] == y[0] && x[1] < y[1];
         });

    int n = intervals.size();
    int c = 0;
    int max_seen = -1;

    for (int i = 0; i < n; i++) {
      vector<int> &v = intervals[i];
      if (v[0] == -1) {
        continue;
      }

      int j = i + 1;

      for (; j < n && intervals[j][0] == v[0]; j++) {
        intervals[j - 1][0] = -1;
        c++;
      }

      v = intervals[i];

      if (v[0] == -1) {
        continue;
      }

      if (v[1] <= max_seen) {
        intervals[i][0] = -1;
        c++;
      } else {
        max_seen = v[1];
      }
    }

    return n - c;
  }
};

int main() {
  vector<vector<int>> intervals{{1, 4}, {3, 6},  {2, 8},  {1, 3},
                                {2, 6}, {4, 6},  {7, 12}, {1, 7},
                                {5, 9}, {6, 11}, {4, 14}, {10, 12}};
  Solution sol;
  cout << sol.removeCoveredIntervals(intervals) << "\n";

  return 0;
}
