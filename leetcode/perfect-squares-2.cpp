// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i < n + 1; i++) {
            dp[i] = INT_MAX;
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
