// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n * k), memory: O(n * k)
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1);
        int i = 0;
        while(i < n) {
            dp[i] = vector<int>(2 * k, -1);
            i++;
        }
        dp[n] = vector<int>(2 * k, 0);
        int res = 0;
        int opt = 0;
        while(opt < 2 * k) {
            fill(0, opt, k, prices, dp);
            res = max(res, dp[0][opt]);
            opt += 2;
        }
        return res;
    }

    void fill(int i, int opt, int k, vector<int>& p, vector<vector<int>>& dp) {
        int n = p.size();
        if (n <= i || 2 * k <= opt || dp[i][opt] != -1) {
            return;
        }
        fill(i + 1, opt + 1, k, p, dp);
        fill(i + 1, opt, k, p, dp);
        int c1 = (opt % 2 == 0 ? -1 : 1) * p[i] + (opt + 1 == 2 * k ? 0 : dp[i + 1][opt + 1]);
        int c2 = dp[i + 1][opt];
        dp[i][opt] = max(c1, c2);
    }
};

int main() {
    vector<int> prices = {13, 8, 18, 1, 7, 8, 12, 15, 4, 19, 11, 10, 17, 19, 2, 20, 6, 11, 9, 2, 4, 20, 9, 12, 4, 7, 15, 9, 7, 13, 8, 14, 1, 13, 2, 14, 4, 2, 13, 20, 3, 0, 20, 3, 6, 8, 5, 17, 11, 11, 7, 20, 19, 10, 9, 7, 16, 1, 17, 12, 2, 19, 1, 11, 17, 17, 1, 16, 17, 8, 4, 0, 12, 11, 20, 13, 18, 2, 5, 14, 6, 10, 2, 0, 0, 0, 19, 17, 8, 19, 5, 0, 3, 9, 13, 3, 4, 12, 17, 0};
    int k = 7;
    Solution sol;
    cout << sol.maxProfit(k, prices);
    cout << endl;
    return 0;
}
