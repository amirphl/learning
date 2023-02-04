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
        unordered_map<uint64_t, int> dp;
        int n = s.length();
        return rec(s, dp, 0, n - 1);
    }

    int rec(string& s, unordered_map<uint64_t, int>& dp, int i, int j) {
        uint64_t h = hash(i, j);

        if (dp.find(h) != dp.end()) {
            return dp[h];
        }

        if (i >= j) {
            return dp[h] = 0;
        }

        while(i < j) {
            if (s[i] == 'a') {
                i++;
            } else if (s[j] == 'b') {
                j--;
            } else {
                return dp[h] = 1 + min(rec(s, dp, i + 1, j), rec(s, dp, i, j - 1));
            }
        }

        return dp[h] = 0;
    }

    uint64_t hash(int i, int j) {
        uint64_t h = i;
        h = h << 32;
        return h + j;
    }
};
