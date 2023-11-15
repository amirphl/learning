// https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include "bits/stdc++.h"
using namespace std;

bool visited[100][100];
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid[0][0]) {
      return -1;
    }
    int n = grid.size();
    int m = grid[0].size();
    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = 1;
    int u, v;
    while (!q.empty()) {
      int x = q.front().first.first;
      int y = q.front().first.second;
      int d = q.front().second;
      q.pop();
      if (x == n - 1 && y == m - 1) {
        return d;
      }
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          u = x + i;
          v = y + j;
          if (!in_grid(u, v, n, m, grid) || grid[u][v] || visited[u][v]) {
            continue;
          }
          visited[u][v] = 1;
          q.push({{u, v}, d + 1});
        }
      }
    }
    return -1;
  }

  bool in_grid(int x, int y, int n, int m, vector<vector<int>> &grid) {
    return 0 <= x && x < n && 0 <= y && y < m;
  }
};
