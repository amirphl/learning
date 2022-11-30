// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*>*** dp;

    vector<TreeNode*> generateTrees(int n) {
        dp = new vector<TreeNode*>**[n + 2];
        int i = 0;
        while(i < n + 2) {
            dp[i] = new vector<TreeNode*>*[n + 2];
            int j = 0;
            while(j < n + 2) {
                dp[i][j] = nullptr;
                j++;
            }
            i++;
        }

        genRec(1, n);
        // TODO delete dp
        return *dp[1][n];
    }

    void genRec(int i, int j) {
        if (dp[i][j] != nullptr) {
            return;
        }

        dp[i][j] = new vector<TreeNode*>;

        if (i > j) {
            dp[i][j] -> push_back(nullptr);
            return;
        }

        int c = i;
        while(c <= j) {
            genRec(i, c - 1);
            genRec(c + 1, j);
            for(int p = 0; p < dp[i][c - 1] -> size(); p++) {
                for(int q = 0; q < dp[c + 1][j] -> size(); q++) {
                    TreeNode* root = new TreeNode(c);
                    root -> left = dp[i][c - 1] -> at(p);
                    root -> right = dp[c + 1][j] -> at(q);
                    dp[i][j] -> push_back(root);
                }
            }
            c++;
        }
    }
};
