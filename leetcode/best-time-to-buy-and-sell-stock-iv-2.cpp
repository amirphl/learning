// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int k;
    int maxProfit(int k, vector<int>& p) {
        this -> k = k;
        int n = p.size();

        if (n == 1) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2*k, -1));

        return max({0, recur(p, dp, 1, 0), recur(p, dp, 1, 1) - p[0]});
    }

    int recur(vector<int>& p, vector<vector<int>>& dp, int pos, int opt) {
        int n = p.size();

        if (opt == 2*k || pos == n) {
            return 0;
        }

        if (dp[pos][opt] != -1) {
            return dp[pos][opt];
        }

        int c = opt % 2 == 0 ? -1 : 1;

        return dp[pos][opt] = max({0, recur(p, dp, pos + 1, opt), recur(p, dp, pos + 1, opt + 1) + c * p[pos]});
    }
};
