// https://leetcode.com/problems/scramble-string/

class Solution {
public:
    unordered_map<uint32_t, bool> dp;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (s1.length() != s2.length()) {
            return false;
        }

        return recur(s1, s2, 0, s1.length() - 1, 0, s2.length() - 1);
    }

    uint32_t hash(uint8_t i, uint8_t j, uint8_t u, uint8_t v) {
        uint32_t h;
        h = i;
        h = h << 8;
        h += j;
        h = h << 8;
        h += u;
        h = h << 8;
        h += v;
        return h;
    }

    bool recur(string& s1, string& s2, uint8_t i, uint8_t j, uint8_t u, uint8_t v) {
        uint32_t h = hash(i, j, u, v);

        if (dp.find(h) != dp.end()) {
            return dp[h];
        }
        if (i == j) {
            return dp[h] = s1[i] == s2[u];
        }
        if (s1[i] == s2[u]) {
            return dp[h] = recur(s1, s2, i + 1, j, u + 1, v);
        } else {
            for(uint8_t p = 0; p < j - i; p++) {
                bool sat = (recur(s1, s2, i, i + p, v - p, v) &&
                            recur(s1, s2, i + p + 1, j, u, v - p - 1)) ||
                           (recur(s1, s2, i, i + p, u, u + p) &&
                            recur(s1, s2, i + p + 1, j, u + p + 1, v));
                if (sat) {
                    return dp[h] = true;
                }
            }
        }

        return dp[h] =false;
    }
};
