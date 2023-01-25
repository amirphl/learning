// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 1;
        int start = 0;
        int end = 0;
        int dp[n];

        for(int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            int old_val;

            if (i + 1 < n) {
                old_val = dp[i + 1];
                dp[i + 1] = (s[i] == s[i + 1] ? 2 : 1);

                if (dp[i + 1] > max_len) {
                    max_len = dp[i + 1];
                    start = i;
                    end = i + 1;
                }
            }

            for(int j = i + 2; j < n; j++) {
                int backup = dp[j];
                dp[j] = max(dp[j], old_val);

                if (s[i] == s[j]) {
                    dp[j] = max({dp[j], (old_val == j - i - 1 ? j - i + 1 : 0)});
                }

                if (dp[j] > max_len) {
                    max_len = dp[j];
                    start = i;
                    end = j;
                }

                old_val = backup;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
