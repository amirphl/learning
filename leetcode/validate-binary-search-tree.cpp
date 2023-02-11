// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* r;
        int64_t prev = 2 * (int64_t) INT_MIN;
        int ans = 1;

        while(curr) {
            if (curr -> left) {
                r = curr -> left;

                while(r -> right && r -> right != curr) {
                    r = r -> right;
                }

                if (r -> right) {
                    r -> right = 0;

                    if (ans && prev >= (curr -> val)) {
                        ans = 0;
                    }
                    prev = curr -> val;

                    curr = curr -> right;
                } else {
                    r -> right = curr;
                    curr = curr -> left;
                }
            } else {
                if (ans && prev >= (curr -> val)) {
                    ans = 0;
                }
                prev = curr -> val;

                curr = curr -> right;
            }
        }

        return ans;
    }
};
