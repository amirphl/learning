// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        int i = 1;
        while(i < n + 1) {
            dp[i] = INT_MAX;
            int j = 1;
            while(j * j <= i) {
                dp[i] = min(dp[i], dp[i - j * j]);
                j++;
            }
            dp[i]++;
            i++;
        }
        return dp[n];
    }
};
