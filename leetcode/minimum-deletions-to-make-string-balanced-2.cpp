// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution {
public:
    // aaaaa b
    // b ... a : not allowed
    // aaa .... bbb
    // aaabbb
    // aaab .... abbb
    // TLE
    int minimumDeletions(string s) {
        int n = s.length();
        int ans = n;
        int prev = 0;

        for(int i = 0, c = 0; i < n; i++) {
            if (s[i] == 'a') {
                prev = min(c, 1 + prev);
            } else {
                c++;
            }
        }

        return prev;
    }
};
