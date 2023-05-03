// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        rec(root, val);
        return root;
    }

    void rec(TreeNode* root, int val) {
        if (root -> val < val) {
            if (root -> right) {
                rec(root -> right, val);
            } else {
                root -> right = new TreeNode(val);
            }
        } else {
            if (root -> left) {
                rec(root -> left, val);
            } else {
                root -> left = new TreeNode(val);
            }
        }
    }
};
