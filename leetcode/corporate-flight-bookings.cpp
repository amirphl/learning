// https://leetcode.com/problems/corporate-flight-bookings/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> arr(n, 0);
    for (auto &b : bookings) {
      int frst = b[0];
      int last = b[1];
      int seat = b[2];
      arr[frst - 1] += seat;
      if (last < n)
        arr[last] -= seat;
    }
    for (int i = 1; i < n; i++) {
      arr[i] += arr[i - 1];
    }
    return arr;
  }
};

int main() {
  vector<vector<int>> bookings{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
  int n = 5;
  Solution sol;
  vector<int> res = sol.corpFlightBookings(bookings, 5);
  for (auto &x : res) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}
