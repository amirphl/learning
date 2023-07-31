// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include "bits/stdc++.h"
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
  int widthOfBinaryTree(TreeNode *root) {
    queue<pair<TreeNode *, uint64_t>> q;
    q.push({root, 1});
    q.push({0, 0});
    uint64_t min_seen = 0, max_seen, res = 0;
    while (!q.empty()) {
      TreeNode *node = q.front().first;
      uint64_t num = q.front().second;
      q.pop();
      if (!node) {
        uint64_t diff = max_seen - min_seen + 1;
        res = res > diff ? res : diff;
        min_seen = 0;
        if (q.empty()) {
          break;
        } else {
          q.push({0, 0});
        }
        continue;
      }
      max_seen = num;
      if (min_seen == 0) {
        min_seen = num;
      }
      if (node->left) {
        q.push({node->left, num * 2});
      }
      if (node->right) {
        q.push({node->right, num * 2 + 1});
      }
    }
    return res;
  }
};
