// https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    // memory optimized
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        int c = (2 * nums[1] == nums[0] + nums[2] ? 1 : 0);
        int i = 3;
        int res = c;
        while(i < n) {
            if (2 * nums[i - 1] == nums[i - 2] + nums[i]) {
                c++;
            } else {
                c = 0;
            }
            res += c;
            i++;
        }
        return res;
    }

    int numberOfArithmeticSlices2(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        int dp[n];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = (2 * nums[1] == nums[0] + nums[2] ? 1 : 0);
        int i = 3;
        int res = dp[2];
        while(i < n) {
            if (2 * nums[i - 1] == nums[i - 2] + nums[i]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 0;
            }
            res += dp[i];
            i++;
        }
        return res;
    }
};
