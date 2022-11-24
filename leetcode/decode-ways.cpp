// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n];
        if (s[n - 1] == '0') {
            dp[n - 1] = 0;
        } else {
            dp[n - 1] = 1;
        }
        int i = n - 2;
        while(i >= 0) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                string mid = s.substr(i, 2);
                if (stoi(mid) <= 26) {
                    dp[i] += (i + 2 < n ? dp[i + 2] : 1);
                }
            }
            i--;
        }
        return dp[0];
    }
};
