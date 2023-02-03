// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n == 0) {
            return m;
        }
        if (m == 0) {
            return n;
        }

        int dp[n][m];
        int app_1[26];
        int app_2[26];

        for(int i = 0; i < 26; i++) {
            app_1[i] = INT_MAX;
            for(int j = 0; j < n; j++) {
                if (s[j] == 'a' + i) {
                    app_1[i] = j;
                    break;
                }
            }
        }

        for(int i = 0; i < 26; i++) {
            app_2[i] = INT_MAX;
            for(int j = 0; j < m; j++) {
                if (t[j] == 'a' + i) {
                    app_2[i] = j;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    if (s[i] == t[j]) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = 1;
                    }
                } else if (i == 0) {
                    if (s[i] == t[j]) {
                        dp[i][j] = j;
                    } else {
                        if (app_2[s[i] - 'a'] <= j) {
                            dp[i][j] = j;
                        } else {
                            dp[i][j] = j + 1;
                        }
                    }
                } else if (j == 0) {
                    if (s[i] == t[j]) {
                        dp[i][j] = i;
                    } else {
                        if (app_1[t[j] - 'a'] <= i) {
                            dp[i][j] = i;
                        } else {
                            dp[i][j] = i + 1;
                        }
                    }
                } else {
                    if (s[i] == t[j]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
