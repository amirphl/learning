// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 N* };
 */
class Solution {
public:
  int maxAncestorDiff(TreeNode *root) {
    int64_t min_found = INT_MAX, max_found = INT_MIN, ans = INT_MIN;
    rec(root, ans, min_found, max_found);
    return ans;
  }

  void rec(TreeNode *root, int64_t &ans, int64_t &min_found,
           int64_t &max_found) {
    if (root->left == 0 && root->right == 0) {
      min_found = root->val;
      max_found = root->val;
      return;
    }

    int64_t left_min = INT_MAX, right_min = INT_MAX, left_max = INT_MIN,
            right_max = INT_MIN;
    const int64_t v = root->val;

    if (root->left) {
      rec(root->left, ans, left_min, left_max);
      vector<int64_t> c = {max_found, left_max, v};
      max_found = mymax(c);
      vector<int64_t> b = {min_found, left_min, v};
      min_found = mymin(b);
      vector<int64_t> a = {ans, myabs(v - left_min), myabs(v - left_max)};
      ans = mymax(a);
    }

    if (root->right) {
      rec(root->right, ans, right_min, right_max);
      vector<int64_t> c = {max_found, right_max, v};
      max_found = mymax(c);
      vector<int64_t> b = {min_found, right_min, v};
      min_found = mymin(b);
      vector<int64_t> a = {ans, myabs(v - right_min), myabs(v - right_max)};
      ans = mymax(a);
    }

    // cout << root->val << " " << ans << " " << min_found << " " << max_found
         // << endl;
  }

  int64_t mymax(vector<int64_t> &n) {
    int64_t m = INT_MIN;
    for (auto &x : n) {
      if (x > m) {
        m = x;
      }
    }
    return m;
  }

  int64_t mymin(vector<int64_t> &n) {
    int64_t m = INT_MAX;
    for (auto &x : n) {
      if (x < m) {
        m = x;
      }
    }
    return m;
  }

  int64_t myabs(int64_t val) { return (val < 0) ? -val : val; }
};
