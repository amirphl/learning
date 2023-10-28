// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
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
  int averageOfSubtree(TreeNode *root) {
    int sum, cnt;
    return rec(root, sum, cnt);
  }

  int rec(TreeNode *root, int &sum, int &cnt) {
    if (!root) {
      sum = 0;
      cnt = 0;
      return 0;
    }
    int left_sum, left_cnt;
    int left_ans = rec(root->left, left_sum, left_cnt);
    int right_sum, right_cnt;
    int right_ans = rec(root->right, right_sum, right_cnt);
    sum = left_sum + right_sum + root->val;
    cnt = left_cnt + right_cnt + 1;
    int ans = left_ans + right_ans + (root->val == sum / cnt);
    return ans;
  }
};
