// https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
#include "bits/stdc++.h"
using namespace std;

const int N = 100;
bool visited[N];
int cnt = 0;
class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    memset(visited, 0, sizeof(visited));
    cnt = 0;
    rec(strs);
    return cnt;
  }
  void rec(vector<string> &strs) {
    const int n = strs.size();
    const int m = strs[0].length();
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[j]) {
          continue;
        }
        if (strs[i][j] > strs[i + 1][j]) {
          visited[j] = 1;
          cnt++;
        } else if (strs[i][j] < strs[i + 1][j]) {
          break;
        }
      }
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[j]) {
          continue;
        }
        if (strs[i][j] > strs[i + 1][j]) {
          rec(strs);
          return;
        } else if (strs[i][j] < strs[i + 1][j]) {
          break;
        }
      }
    }
  }
};
