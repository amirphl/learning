// https://leetcode.com/problems/subsets-ii/

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    unordered_set<vector<int>, VectorHash> s;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        fill(0, nums);

        return res;
    }

    void fill(int i, vector<int>& nums) {
        if (i == nums.size()) {
            vector<int> u = v;
            sort(u.begin(), u.end());

            if (s.find(u) == s.end()) {
                res.push_back(u);
                s.insert(u);
            }

            return;
        }

        fill(i + 1, nums);
        v.push_back(nums[i]);
        fill(i + 1, nums);
        v.pop_back();
    }
};
