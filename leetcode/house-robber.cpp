// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[n - 1] = nums[n - 1];
        int i = n - 2;
        while(i >= 0) {
            dp[i] = max(dp[i + 1], (i + 2 < n ? dp[i + 2] : 0) + nums[i]);
            i--;
        }
        return dp[0];
    }
};
