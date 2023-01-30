// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        uint64_t dp[m];
        uint64_t prev, next;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                uint64_t next = dp[j];
                if (s[i] == t[j]) {
                    if (i == n - 1 && j == m - 1) {
                        dp[j] = 1;
                    } else if (j == m - 1) {
                        dp[j] = 1 + (i + 1 < n ? dp[j] : 0);
                    } else if (i == n - 1) {
                        dp[j] = 0;
                    } else {
                        dp[j] = prev + dp[j];
                    }
                } else {
                    dp[j] = (i + 1 < n ? dp[j] : 0);
                }
                prev = next;
            }
        }

        return dp[0];
    }
};
