// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int cand = i + 1, j;

                for(j = i + 1; j < n; j++) {
                    if (nums[i] < nums[j] && nums[j] < nums[cand]) {
                        cand = j;
                    }
                }

                swap(nums, i, cand);
                sort(nums.begin() + i + 1, nums.end());

                return;
            }
        }

        sort(nums.begin(), nums.end());
    }
};
