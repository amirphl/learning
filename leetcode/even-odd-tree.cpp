// https://leetcode.com/problems/even-odd-tree/
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    q.push(0);
    int lvl = 0;
    TreeNode *prev = 0;
    while (q.size() > 1) {
      TreeNode *node = q.front();
      q.pop();
      if (node && !prev && (q.empty() || !(q.front()))) {
        if ((lvl & 1 && (node->val) & 1) ||
            (!(lvl & 1) && !((node->val) & 1))) {
          return false;
        }
      }
      if (node == 0) {
        lvl++;
        prev = 0;
        q.push(0);
        continue;
      }
      if (prev) {
        if (lvl & 1) {
          if ((node->val & 1) || prev->val <= node->val) {
            return 0;
          }
        } else {
          if (!(node->val & 1) || prev->val >= node->val) {
            return 0;
          }
        }
      }
      prev = node;
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
    return 1;
  }
};
