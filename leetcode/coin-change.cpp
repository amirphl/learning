// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        int n = coins.size();
        int dp[m + 1];
        dp[0] = 0;
        int i = 1, diff;

        while(i <= m) {
            dp[i] = INT_MAX;
            int j = 0;

            while(j < n) {
                diff = i - coins[j];
                dp[i] = min(dp[i], (diff >= 0 && dp[diff] != INT_MAX ? dp[diff] + 1 : INT_MAX));
                j++;
            }
            i++;
        }

        return (dp[m] == INT_MAX ? -1 : dp[m]);
    }
};
