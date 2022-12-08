// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) {
            return result;
        }

        vector<int> row;
        deque<TreeNode*> q;
        q.push_back(0);
        q.push_back(root);
        int lvl = 0;

        while(q.size() > 1) {
            if (lvl % 2 == 1) {
                TreeNode* curr = q.front();

                if (curr == 0) {
                    lvl++;
                    result.push_back(row);
                    row = vector<int>();
                    continue;
                }

                q.pop_front();
                row.push_back(curr -> val);

                if (curr -> right) {
                    q.push_back(curr -> right);
                }
                if (curr -> left) {
                    q.push_back(curr -> left);
                }
            } else {
                TreeNode* curr = q.back();

                if (curr == 0) {
                    lvl++;
                    result.push_back(row);
                    row = vector<int>();
                    continue;
                }

                q.pop_back();
                row.push_back(curr -> val);

                if (curr -> left) {
                    q.push_front(curr -> left);
                }
                if (curr -> right) {
                    q.push_front(curr -> right);
                }
            }
        }

        result.push_back(row);
        return result;
    }
};
