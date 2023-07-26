// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

class Solution {
public:
  int minimumHammingDistance(vector<int> &source, vector<int> &target,
                             vector<vector<int>> &allowedSwaps) {
    int n = source.size();
    int arr[n];
    memset(arr, -1, sizeof(arr));

    for (auto &e : allowedSwaps) {
      int x = e[0];
      int y = e[1];

      if (x == y)
        continue;

      if (arr[x] == -1 && arr[y] == -1) {
        arr[x] = y;
      } else if (arr[x] == -1) {
        int r = findRoot(arr, n, y);
        if (x != r)
          arr[x] = r;
      } else if (arr[y] == -1) {
        int r = findRoot(arr, n, x);
        if (y != r)
          arr[y] = r;
      } else if (arr[x] != arr[y]) {
        int r1 = findRoot(arr, n, x);
        int r2 = findRoot(arr, n, y);

        if (r1 != r2) {
          arr[r1] = r2;
        }
      }
    }

    stack<int> s;
    for (int i = 0; i < n; i++) {
      int j = i, k;
      while (j != -1) {
        s.push(j);
        k = j;
        j = arr[j];
      }
      s.pop();
      if (s.size() == 0) {
        continue;
      }
      while (!s.empty()) {
        j = s.top();
        s.pop();
        arr[j] = k;
      }
      s = stack<int>();
    }

    unordered_map<int, unordered_map<int, int>> f;

    for (int i = 0; i < n; i++) {
      int g = arr[i] == -1 ? i : arr[i];

      if (f.find(g) == f.end()) {
        f[g] = unordered_map<int, int>();
      }

      int s = source[i];

      if (f[g].find(s) == f[g].end()) {
        f[g][s] = 0;
      }

      f[g][s]++;
    }

    for (int i = 0; i < n; i++) {
      int g = arr[i] == -1 ? i : arr[i];

      int t = target[i];

      if (f[g].find(t) == f[g].end()) {
        f[g][t] = 0;
      }

      f[g][t]--;
    }

    int dist = 0;
    for (auto &p1 : f) {
      for (auto &p2 : p1.second) {
        int freq = p2.second;
        if (freq > 0) {
          dist += freq;
        }
      }
    }

    return dist;
  }

  int findRoot(int arr[], int n, int x) {
    while (arr[x] != -1) {
      x = arr[x];
    }
    return x;
  }
};

int main() {
  vector<int> source{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  vector<int> target{5, 6, 14, 3, 11, 4, 4, 5, 2, 12, 4, 5, 2, 1};
  vector<vector<int>> allowedSwaps{{1, 0},   {2, 3},   {0, 4},   {5, 1},
                                   {3, 6},   {6, 8},   {8, 7},   {9, 0},
                                   {10, 11}, {11, 12}, {12, 10}, {12, 10},
                                   {12, 11}, {10, 12}, {11, 11}, {6, 13}};
  Solution sol;
  cout << sol.minimumHammingDistance(source, target, allowedSwaps) << endl;

  return 0;
}
