// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = 0;

        while(i < n - 1) {
            if (nums[i] == nums[i + 1]) {
                ans++;
                i++;
            } else {
                i += 2;
            }
        }

        if ((n - ans) % 2 == 1) {
            ans++;
        }

        return ans;
    }
};
