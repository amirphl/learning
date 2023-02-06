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
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<uint64_t, vector<TreeNode*>*> dp;
        vector<TreeNode*>* v = gen(1, n, dp);
        return *v;
    }

    vector<TreeNode*>* gen(const uint32_t low, const uint32_t high, unordered_map<uint64_t, vector<TreeNode*>*>& dp) {
        uint64_t h = hash(low, high);

        if (dp.find(h) != dp.end()) {
            return dp[h];
        }

        vector<TreeNode*>* v = new vector<TreeNode*>();
        if (high < low) {
            v -> push_back(nullptr);
            return dp[h] = v;
        }

        for(uint32_t i = low; i <= high; i++) {
            vector<TreeNode*>* left_v = gen(low, i - 1, dp);
            vector<TreeNode*>* right_v = gen(i + 1, high, dp);
            for(uint32_t j = 0; j < left_v -> size(); j++) {
                for(uint32_t k = 0; k < right_v -> size(); k++) {
                    TreeNode* root = new TreeNode(i, left_v -> at(j), right_v -> at(k));
                    v -> push_back(root);
                }
            }
        }

        return dp[h] = v;
    }

    uint64_t hash(uint32_t low, uint32_t high) {
        uint64_t h = low;
        h = h << 32;
        return h + high;
    }
};
