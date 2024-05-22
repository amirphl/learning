// https://leetcode.com/problems/steps-to-make-array-non-decreasing/
#include <bits/stdc++.h>
#include <utility>

using namespace std;

class Solution {
public:
  int totalSteps(vector<int> &nums) {
    int res = 0;
    stack<pair<int, int>> s;
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
      int cnt = 0;
      while (!s.empty() && *it > s.top().first) {
        if (cnt < s.top().second) {
          cnt = s.top().second;
        } else {
          cnt++;
        }
        s.pop();
      }
      res = max(res, cnt);
      s.push(make_pair(*it, cnt));
    }
    return res;
  }
};

int main() {
  vector<int> v{5, 4, 3, 2, 1, 4, 3, 2, 1, 3, 2, 1, 1, 1, 1,
                4, 3, 4, 1, 2, 1, 5, 4, 3, 2, 1, 7, 5, 4, 3,
                2, 1, 7, 7, 7, 7, 8, 8, 8, 8, 4, 3, 2, 1};
  Solution sol;
  cout << sol.totalSteps(v) << "\n";
  return 0;
}
