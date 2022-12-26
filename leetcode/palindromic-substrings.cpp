// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int dp[n];
        bool is_pal[n];
        memset(is_pal, 0, sizeof(is_pal));

        int prv_dp;
        bool prv_is_pal;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                int backup_dp = dp[j];
                bool backup_is_pal = is_pal[j];

                if (i == j) {
                    dp[j] = 1;
                    is_pal[j] = true;
                } else if (i + 1 == j) {
                    dp[j] = 2;
                    is_pal[j] = false;

                    if (s[i] == s[j]) {
                        dp[j]++;
                        is_pal[j] = true;
                    }
                } else {
                    dp[j] = dp[j] + dp[j - 1] - prv_dp;
                    is_pal[j] = false;

                    if (s[i] == s[j] && prv_is_pal) {
                        dp[j]++;
                        is_pal[j] = true;
                    }
                }

                prv_dp = backup_dp;
                prv_is_pal = backup_is_pal;
            }
        }

        return dp[n - 1];
    }
};
