// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        if (n == 1) {
            return 0;
        }

        int dp[n][4];
        memset(dp, -1, sizeof(dp));

        return max({0, recur(p, dp, 1, 0), recur(p, dp, 1, 1) - p[0]});
    }

    int recur(vector<int>& p, int dp[][4], int pos, int opt) {
        int n = p.size();

        if (opt == 4 || pos == n) {
            return 0;
        }

        if (dp[pos][opt] != -1) {
            return dp[pos][opt];
        }

        int c = opt % 2 == 0 ? -1 : 1;

        return dp[pos][opt] = max({0, recur(p, dp, pos + 1, opt), recur(p, dp, pos + 1, opt + 1) + c * p[pos]});
    }
};
