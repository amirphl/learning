// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
  int mod = 1e9 + 7;
  unordered_map<TreeNode *, uint64_t> sums;

public:
  int maxProduct(TreeNode *root) {
    rec(root);
    uint64_t ans = 0;
    uint64_t total = sums[root];
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        TreeNode *r = curr->left;
        while (r->right && r->right != curr) {
          r = r->right;
        }
        if (r->right) {
          r->right = 0;
          uint64_t s1 = total - sums[curr];
          uint64_t s2 = sums[curr];
          if (ans < s1 * s2) {
            ans = s1 * s2;
          }
          curr = curr->right;
        } else {
          r->right = curr;
          curr = curr->left;
        }
      } else {
        uint64_t s1 = total - sums[curr];
        uint64_t s2 = sums[curr];
        if (ans < s1 * s2) {
          ans = s1 * s2;
        }
        curr = curr->right;
      }
    }
    return ans % mod;
  }

  void rec(TreeNode *root) {
    if (!root) {
      return;
    }
    rec(root->left);
    rec(root->right);
    uint64_t s = root->val;
    if (root->left) {
      s += sums[root->left];
    }
    if (root->right) {
      s += sums[root->right];
    }
    sums[root] = s;
  }
};
