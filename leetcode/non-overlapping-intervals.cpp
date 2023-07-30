// https://leetcode.com/problems/non-overlapping-intervals/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // TLE
  int eraseOverlapIntervals(vector<vector<int>> &in) {
    sort(in.begin(), in.end(), [](vector<int> &x, vector<int> &y) {
      return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
    });

    int c = 0;
    int prev = -5 * (int)1e4 - 1;

    for (auto it = in.begin(); it != in.end();) {
      // cout << (*it)[0] << " " << (*it)[1] << endl;
      int start = (*it)[0];
      if (start == prev) {
        // cout << "DEL" << endl;
        in.erase(it);
        c++;
        continue;
      }
      prev = start;
      it++;
    }

    int n = in.size();
    int dp[n];
    memset(dp, -1, sizeof(dp));

    return c + f(in, 0, dp);
  }
  int f(vector<vector<int>> &in, int start, int dp[]) {
    int n = in.size();

    if (n - 1 <= start) {
      return 0;
    }
    if (dp[start] != -1) {
      return dp[start];
    }

    int s = in[start][0];
    int e = in[start][1];

    int pos = bs(in, start + 1, n - 1, e);
    if (pos == -1) {
      pos = n;
    }

    int res1 = f(in, pos, dp);
    int res2 = f(in, start + 1, dp);
    // cout << start << " " << res1 << " " << pos << " " << res2 << " : " <<
    // min(res1 + pos - start - 1, res2 + 1) << endl;

    return dp[start] = min(res1 + pos - start - 1, res2 + 1);
  }

  int bs(vector<vector<int>> &in, int low, int high, int elem) {
    while (low <= high) {
      // cout << low << " " << high << " " << elem << endl;
      if (low == high) {
        return elem <= in[low][0] ? low : -1;
      }
      int mid = (low + high) >> 1;
      if (in[mid][0] < elem) {
        low = mid + 1;
      } else {
        high = mid;
      }
      // cout << mid << " __ " << low << " __ " << high << " __ " << in[mid][0]
      // << endl;
    }
    return -1;
  }
};
