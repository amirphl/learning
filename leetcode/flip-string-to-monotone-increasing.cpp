// https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int dp = 0, c = 0;

        if (s[0] == '1') {
            c = 1;
        }

        for(int i = 1; i < n; i++) {
            if (s[i] == '0') {
                dp = min(1 + dp, c);
            } else {
                c++;
            }
        }

        return dp;
    }
};
