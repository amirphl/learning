// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        if (n == 0) {
            return 0;
        }

        int index[n];
        unordered_map<int, int> m;

        for(int i = 0; i < n; i++) {
            m[preorder[i]] = i;
        }

        for(int i = 0; i < n; i++) {
            index[i] = m[postorder[i]];
        }

        return rec(preorder, postorder, index, 0, n - 1, 0, n - 1);
    }

    TreeNode* rec(vector<int>& preorder, vector<int>& postorder, int index[], int a, int b, int c, int d) {
        if (a > b) {
            return 0;
        }
        if (a == b) {
            return new TreeNode(preorder[a]);
        }

        int max_dist = INT_MIN;
        int i = c;
        for(; i < d; i++) {
            max_dist = max(max_dist, index[i]);
            if (max_dist - (a + 1) == i - c) {
                break;
            }
        }

        // printf("%d %d %d %d %d\n", a, b, c, d, max_dist);

        TreeNode* root = new TreeNode(preorder[a]);
        root -> left = rec(preorder, postorder, index, a + 1, max_dist, c, i);
        root -> right = rec(preorder, postorder, index, max_dist + 1, b, i + 1, d - 1);

        return root;
    }
};
