// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        int dp[n][k + 1];
        memset(dp, INT_MAX, sizeof(dp));

        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j < k + 1; j++) {
                if (j == 1) {
                    dp[i][j] = prefix[n - 1] - (i > 0 ? prefix[i - 1] : 0);
                    // cout << dp[i][j] << "_" << prefix[n - 1] << " ";
                    continue;
                }

                dp[i][j] = INT_MAX;

                for(int u = 0; u <= n - i - j; u++) {
                    int a = prefix[i + u] - (i > 0 ? prefix[i - 1] : 0); // i -> i + u
                    int b = i + u + 1 < n ? dp[i + u + 1][j - 1] : INT_MIN;
                    int c = max(a, b);
                    dp[i][j] = min(dp[i][j], c);
                    // cout << a << ":" << b << ":" << c << ":" << dp[i][j] << "_";
                }
                // cout << " ";
            }
            // cout << endl;
        }

        return dp[0][k];
    }
};
