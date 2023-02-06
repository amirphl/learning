// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        int offset = 1000;
        const int len = 2 * offset + 1;
        int *dp = new int[len];
        int *prev = new int[len];

        for(int i = 0; i < n; i++) {
            for(int j = -offset; j <= offset; j++) {
                if (i == 0) {
                    if (!j && !nums[i]) {
                        dp[j + offset] = 2;
                    } else {
                        dp[j + offset] = nums[i] == j || nums[i] == -j;
                    }
                    continue;
                }

                dp[j + offset] = 0;

                int x = j - nums[i] + offset;

                if (0 <= x && x < len) {
                    dp[j + offset] += prev[x];
                }

                int y = j + nums[i] + offset;

                if (0 <= y && y < len) {
                    dp[j + offset] += prev[y];
                }
            }
            int *temp = dp;
            dp = prev;
            prev = temp;
        }

        // free dp, prev
        return prev[target + offset];
    }
};
