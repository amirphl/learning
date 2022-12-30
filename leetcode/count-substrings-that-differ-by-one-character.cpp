// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

class Solution {
public:
    // time: O(n^3), memory: O(1)
    int countSubstrings2(string& s, string& t) {
        int count = 0;
        int n = s.length();
        int m = t.length();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < t.length(); j++) {
                int first_mismatch_idx = -1;
                for(int k = 0; k < n - i && k < m - j; k++) {
                    if (s[i + k] != t[j + k]) {
                        if (first_mismatch_idx == -1) {
                            first_mismatch_idx = k;
                            count++;
                        } else {
                            break;
                        }
                    } else if (first_mismatch_idx != -1) {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    // time: O(n^2), memory: O(n^2)
    int countSubstrings3(string& s, string& t) {
        int n = s.length();
        int m = t.length();
        int dp[n][m][2];
        int count = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j][0] = 1 + (i + 1 < n && j + 1 < m ? dp[i + 1][j + 1][0] : 0);
                    dp[i][j][1] = 0 + (i + 1 < n && j + 1 < m ? dp[i + 1][j + 1][1] : 0);
                } else {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 1 + (i + 1 < n && j + 1 < m ? dp[i + 1][j + 1][0] : 0);
                }

                count += dp[i][j][1];
            }
        }

        return count;
    }

    // time: O(n^2), memory: O(n)
    int countSubstrings(string& s, string& t) {
        int n = s.length();
        int m = t.length();
        int dp[m][2];
        int count = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int prev_0, prev_1, backup_0, backup_1;
                backup_0 = dp[j][0];
                backup_1 = dp[j][1];

                if (s[i] == t[j]) {
                    dp[j][0] = 1 + (i + 1 < n && j + 1 < m ? prev_0 : 0);
                    dp[j][1] = 0 + (i + 1 < n && j + 1 < m ? prev_1 : 0);
                } else {
                    dp[j][0] = 0;
                    dp[j][1] = 1 + (i + 1 < n && j + 1 < m ? prev_0 : 0);
                }

                prev_0 = backup_0;
                prev_1 = backup_1;

                count += dp[j][1];
            }
        }

        return count;
    }
};
