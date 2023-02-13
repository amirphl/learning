// https://leetcode.com/problems/find-xor-beauty-of-array/

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int x = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            x ^= nums[i];
        }
        return x;
    }
};
