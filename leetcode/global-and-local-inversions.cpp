// https://leetcode.com/problems/global-and-local-inversions/

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return true;
        }

        int min_found = nums[n - 1];

        for(int i = n - 3; i >= 0; i--) {
            if (nums[i] > min_found) {
                return false;
            }
            min_found = min(min_found, nums[i + 1]);
        }

        return true;
    }
};
