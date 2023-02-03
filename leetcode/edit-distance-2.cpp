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

        int dp[m];
        int app_1[26];
        int app_2[26];
        int prev, backup;

        for(int i = 0; i < 26; i++) {
            app_1[i] = INT_MAX;
            for(int j = 0; j < n; j++) {
                if (s[j] == 'a' + i) {
                    app_1[i] = j;
                    break;
                }
            }
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
                backup = dp[j];
                if (i == 0 && j == 0) {
                    dp[j] = s[i] == t[j] ? 0 : 1;
                } else if (i == 0) {
                    dp[j] = j + (s[i] == t[j] ? 0 : (app_2[s[i] - 'a'] <= j ? 0 : 1));
                } else if (j == 0) {
                    dp[j] = i + (s[i] == t[j] ? 0 : (app_1[t[j] - 'a'] <= i ? 0 : 1));
                } else {
                    dp[j] = s[i] == t[j] ? prev : 1 + min({prev, dp[j], dp[j - 1]});
                }
                prev = backup;
            }
        }

        return dp[m - 1];
    }
};
