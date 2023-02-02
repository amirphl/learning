// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        int n = coins.size();
        int dp[m + 1];
        for(int i = 0; i < n; i++) {
            dp[0] = 0;
            for(int j = 1; j < m + 1; j++) {
                if (i == 0) {
                    dp[j] = (j % coins[i] == 0) ? j / coins[i] : INT_MAX;
                    continue;
                }

                int rem = j - coins[i];
                if (rem >= 0 && dp[rem] != INT_MAX) {
                    dp[j] = min(dp[j], 1 + dp[rem]);
                }
            }
        }

        return dp[m] == INT_MAX ? -1 : dp[m];
    }
};
