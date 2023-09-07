// https://leetcode.com/problems/maximum-students-taking-exam/
#include "bits/stdc++.h"
using namespace std;

class Solution {
  int n;
  int m;

public:
  // TLE
  int maxStudents(vector<vector<char>> &arr) {
    n = arr.size();
    m = arr[0].size();
    int low = 0, high = 64;
    while (low < high) {
      int filled = 0;
      if (low + 1 == high) {
        if (rec(arr, 0, 0, filled, high)) {
          return high;
        }
        return low;
      }
      int mid = (low + high) >> 1;
      if (rec(arr, 0, 0, filled, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }

  bool rec(vector<vector<char>> &arr, const int row, const int col, int &filled,
           const int expected) {
    if (filled == expected) {
      return 1;
    }
    if (n <= row || m <= col) {
      return 0;
    }
    int x = row;
    int y = col + 1;
    if (y == m) {
      x++;
      y = 0;
    }
    bool found = rec(arr, x, y, filled, expected);
    if (arr[row][col] == '#' || found) {
      return found;
    }
    if ((col == 0 || (0 < col && arr[row][col - 1] != '1')) &&
        (col == m - 1 || (col < m - 1 && arr[row][col + 1] != '1')) &&
        (row == 0 || col == 0 ||
         (0 < row && 0 < col && arr[row - 1][col - 1] != '1')) &&
        (row == 0 || col == m - 1 ||
         (0 < row && col < m - 1 && arr[row - 1][col + 1] != '1'))) {
      filled++;
      arr[row][col] = '1';
      found = rec(arr, x, y, filled, expected);
      filled--;
      arr[row][col] = '.';
    }
    return found;
  }
};
