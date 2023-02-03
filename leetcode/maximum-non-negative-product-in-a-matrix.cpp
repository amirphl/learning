// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
public:
    int maxProductPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int64_t dp[n][m][2];
        int mod = 1e9 + 7;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j][0] = dp[i][j][1] = mat[i][j];
                    continue;
                }
                dp[i][j][0] = max({
                    i + 1 < n ? mat[i][j] * dp[i + 1][j][0] : INT_MIN,
                    i + 1 < n ? mat[i][j] * dp[i + 1][j][1] : INT_MIN,
                    j + 1 < m ? mat[i][j] * dp[i][j + 1][0] : INT_MIN,
                    j + 1 < m ? mat[i][j] * dp[i][j + 1][1] : INT_MIN
                });
                dp[i][j][1] = min({
                    i + 1 < n ? mat[i][j] * dp[i + 1][j][0] : INT_MAX,
                    i + 1 < n ? mat[i][j] * dp[i + 1][j][1] : INT_MAX,
                    j + 1 < m ? mat[i][j] * dp[i][j + 1][0] : INT_MAX,
                    j + 1 < m ? mat[i][j] * dp[i][j + 1][1] : INT_MAX
                });
            }
        }

        return 0 <= dp[0][0][0] ? dp[0][0][0] % mod : -1;
    }
};
