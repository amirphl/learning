// https://leetcode.com/problems/longest-univalue-path/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int x, y;
        rec(root, x, y);

        return x - 1;
    }

    void rec(TreeNode* root, int& x, int& y) {
        if (!root) {
            x = 0;
            y = 0;
            return;
        }

        int y_left = 0, y_right = 0;
        int p, q, u, v;

        rec(root -> left, p, q);
        rec(root -> right, u, v);

        if (root -> left && root -> val == root -> left -> val) {
            y_left = q;
        }

        if (root -> right && root -> val == root -> right -> val) {
            y_right = v;
        }

        x = max({p, u, 1 + y_left + y_right});
        y = 1 + max(y_left, y_right);
    }
};
