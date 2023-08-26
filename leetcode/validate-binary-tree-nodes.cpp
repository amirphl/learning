// https://leetcode.com/problems/validate-binary-tree-nodes/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    bool c[n];
    int parent[n];
    memset(c, 0, sizeof(c));
    memset(parent, -1, sizeof(parent));
    int i = 0;
    for (auto &x : leftChild) {
      if (x == -1) {
        i++;
        continue;
      }
      if (c[x]) {
        return 0;
      }
      c[x] = 1;
      int ipar = par(parent, i);
      int xpar = par(parent, x);
      if (ipar == i && xpar == x) {
        parent[x] = i;
      } else if (ipar == i) {
        return 0;
      } else if (xpar == x) {
        if (x == ipar) {
          return 0;
        }
        parent[x] = ipar;
      } else {
        if (ipar == xpar) {
          return 0;
        } else {
          return 0;
        }
      }
      i++;
    }
    i = 0;
    for (auto &x : rightChild) {
      if (x == -1) {
        i++;
        continue;
      }
      if (c[x]) {
        return 0;
      }
      c[x] = 1;
      int ipar = par(parent, i);
      int xpar = par(parent, x);
      if (ipar == i && xpar == x) {
        parent[x] = i;
      } else if (ipar == i) {
        return 0;
      } else if (xpar == x) {
        if (x == ipar) {
          return 0;
        }
        parent[x] = ipar;
      } else {
        if (ipar == xpar) {
          return 0;
        } else {
          return 0;
        }
      }
      i++;
    }
    for (int i = 0; i < n; i++) {
      par(parent, i);
    }
    bool seen = 0;
    unordered_set<int> unique;
    for (int i = 0; i < n; i++) {
      if (parent[i] == -1) {
        if (seen) {
          return 0;
        }
        seen = 1;
      }
      unique.insert(parent[i]);
      if (unique.size() > 2) {
        return 0;
      }
    }
    return 1;
  }

  int par(int parent[], int i) {
    if (parent[i] == -1) {
      return i;
    }
    int p = par(parent, parent[i]);
    parent[i] = p;
    return p;
  }
};
