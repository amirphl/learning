// https://leetcode.com/problems/complete-binary-tree-inserter/
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

class CBTInserter {
  vector<TreeNode *> v;

public:
  CBTInserter(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0) {
      TreeNode *node = q.front();
      v.push_back(node);
      q.pop();
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
  }

  int insert(int val) {
    int n = v.size();
    int p = n / 2;
    if (n % 2 == 0) {
      p = n / 2 - 1;
    }
    TreeNode *node = new TreeNode(val);
    TreeNode *parent = v[p];
    if (parent->left) {
      parent->right = node;
    } else {
      parent->left = node;
    }
    v.push_back(node);
    return parent->val;
  }

  TreeNode *get_root() {
    if (v.size() > 0) {
      return v[0];
    }
    return 0;
  }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
