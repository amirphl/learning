// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int fee;
    int maxProfit(vector<int>& prices, int fee) {
        this -> fee = fee;
        int n = prices.size();
        if (n == 1) {
            return 0;
        }
        int dp[n][2];
        for(int i = 0; i < n; i++) {
            dp[i][0] = dp[i][1] = INT_MAX;
        }

        return func(prices, dp, 0, 0);
    }

    int func(vector<int>& prices, int dp[][2], int idx, short opt) {
        if (dp[idx][opt] != INT_MAX) {
            return dp[idx][opt];
        }

        int n = prices.size();
        if (idx == n - 1) {
            return dp[idx][opt] = opt == 0 ? 0 : prices[idx] - fee;
        }

        if (opt == 0) {
            dp[idx][opt] = max({0, func(prices, dp, idx + 1, 1) - prices[idx], func(prices, dp, idx + 1, 0)});
        } else {
            dp[idx][opt] = max(func(prices, dp, idx + 1, 0) + prices[idx] - fee, func(prices, dp, idx + 1, 1));
        }

        return dp[idx][opt];
    }
};
