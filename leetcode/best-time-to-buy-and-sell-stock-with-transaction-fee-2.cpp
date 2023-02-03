// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int fee;
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 1) {
            return 0;
        }
        int next_buy = 0;
        int next_sell = prices[n - 1] - fee;
        for(int i = n - 2; i >= 0; i--) {
            int temp_1 = max({0, next_sell - prices[i], next_buy});
            int temp_2 = max({next_buy + prices[i] - fee, next_sell});
            next_buy = temp_1;
            next_sell = temp_2;
        }

        return next_buy;
    }
};
