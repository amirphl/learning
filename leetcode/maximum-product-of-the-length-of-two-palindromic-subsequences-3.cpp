// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
public:
    int maxProduct(string s) {
        int len = s.length();
        int mask = (1 << len) - 1;
        int ans = 1;
        int dp[mask + 1];

        for(int i = mask; i; i--) {
            dp[i] = pal(s, i);
        }

        for(int i = mask; i; i--) {
            if (dp[i] && (len - dp[i]) * dp[i] > ans) {
                for(int j = i ^ mask; j; j = (j - 1) & (i ^ mask)) {
                    ans = max(ans, dp[i] * dp[j]);
                }
            }
        }
        return ans;
    }

    int pal(string& s, int mask) {
        int size = 0;
        int n = s.length();
        int i = 0, j = n - 1;
        int p = 1 << i;
        int q = 1 << j;

        while(i < j) {
            if ((p & mask) == 0) {
                p = p << 1;
                j--;
            } else if ((q & mask) == 0) {
                i++;
                q = q >> 1;
            } else if (s[i] != s[j]) {
                return 0;
            } else {
                size += 2;
                p = p << 1;
                q = q >> 1;
                i++;
                j--;
            }
        }
        if (i == j && (mask & (1 << n - i - 1))) {
            size++;
        }
        return size;
    }
};
