// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        int dp[n][k + 1];

        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = 0;
            for(int j = 1; j < k + 1; j++) {
                dp[i][j] = i + 1 < n ? dp[i + 1][j] : INT_MIN;
                int cum = 0;
                int m = j < piles[i].size() ? j : piles[i].size();
                for(int u = 1; u <= m; u++) {
                    cum += piles[i][u - 1];
                    if (i == n - 1) {
                        if (u == j) {
                            dp[i][j] = cum;
                        }
                    } else if (dp[i + 1][j - u] != INT_MIN) {
                        dp[i][j] = max(dp[i][j], cum + dp[i + 1][j - u]);
                    }
                }
            }
        }

        return dp[0][k];
    }
};
