// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        int n = days.size();
        int dp[n];
        dp[n - 1] = *min_element(costs.begin(), costs.end());
        int i = n - 2, j;

        while(i >= 0) {
            dp[i] = INT_MAX;
            j = lower_bound(days.begin() + i, days.end(), days[i] + 1) - days.begin();
            dp[i] = min(dp[i], costs[0] + (j < n ? dp[j] : 0));
            j = lower_bound(days.begin() + i, days.end(), days[i] + 7) - days.begin();
            dp[i] = min(dp[i], costs[1] + (j < n ? dp[j] : 0));
            j = lower_bound(days.begin() + i, days.end(), days[i] + 30) - days.begin();
            dp[i] = min(dp[i], costs[2] + (j < n ? dp[j] : 0));
            i--;
        }

        return dp[0];
    }
};
