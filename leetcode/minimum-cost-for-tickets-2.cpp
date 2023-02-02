// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n];
        dp[n - 1] = min({costs[0], costs[1], costs[2]});
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = costs[0] + dp[i + 1];
            bool seen_7 = false;
            bool seen_30 = false;
            for(int j = 1; j <= 30 && i + j < n; j++) {
                if (days[i + j] > days[i] + 6 && !seen_7) {
                    // cout << " -- " << i << " " << dp[i] << " " << dp[i + j] << " " << costs[1] << endl;
                    dp[i] = min(dp[i], dp[i + j] + costs[1]);
                    seen_7 = true;
                }
                if (days[i + j] > days[i] + 29) {
                    // cout << " ++ " << i << " " << dp[i] << " " << dp[i + j] << " " << costs[2] << endl;
                    dp[i] = min(dp[i], dp[i + j] + costs[2]);
                    seen_30 = true;
                    break;
                }
            }
            if (!seen_7) {
                dp[i] = min(dp[i], costs[1]);
            }
            if (!seen_30) {
                dp[i] = min(dp[i], costs[2]);
            }
            // cout << dp[i] << endl;
        }
        return dp[0];
    }
};
