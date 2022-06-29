// https://leetcode.com/problems/scramble-string/

#include<bits/stdc++.h>

using namespace std;

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<vector<int>, bool, VectorHash> dp;
        return postorder(0, s1.length() - 1, 0, s2.length() - 1, s1, s2, dp);
    }
    bool postorder(int i, int j, int k, int l, string& s1, string& s2, unordered_map<vector<int>, bool, VectorHash>& dp) {
        vector<int> key = {i, j, k, l};
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        // This isn't needed since the inputs are of the same length!
        if (j - i != l - k) {
            dp[key] = false;
            return false;
        }

        // Added this section for optimization.
        // Resolved time limit for testcase:
        // "xstjzkfpkggnhjzkpfjoguxvkbuopi"
        // "xbouipkvxugojfpkzjhnggkpfkzjts"
        if (i == j) {
            bool res = s1[i] == s2[k];
            dp[key] = res;
            return res;
        }

        // Added this section for optimization.
        // Resolved time limit for testcase:
        // "xstjzkfpkggnhjzkpfjoguxvkbuopi"
        // "xbouipkvxugojfpkzjhnggkpfkzjts"
        if (s1.substr(i, j - i + 1) == s2.substr(k, l - k + 1)) {
            dp[key] = true;
            return true;
        }

        // Added this section for optimization.
        // Resolved time limit for testcase:
        // "oatzzffqpnwcxhejzjsnpmkmzngneo"
        // "acegneonzmkmpnsjzjhxwnpqffzzto"
        string copy_s1 = s1.substr(i, j - i + 1), copy_s2 = s2.substr(k, l - k + 1);
        sort(copy_s1.begin(), copy_s1.end());
        sort(copy_s2.begin(), copy_s2.end());
        if (copy_s1 != copy_s2) {
            dp[key] = false;
            return false;
        }

        bool left, right;
        int p = i;
        while(p < j) {
            left = postorder(i, p, k, k + p - i, s1, s2, dp);
            right = postorder(p + 1, j, k + p - i + 1, l, s1, s2, dp);
            if (left && right) {
                dp[key] = true;
                return true;
            }
            left = postorder(i, p, l - (p - i), l, s1, s2, dp);
            right = postorder(p + 1, j, k, l - (p - i) - 1, s1, s2, dp);
            if (left && right) {
                dp[key] = true;
                return true;
            }
            p++;
        }

        dp[key] = false;
        return false;
    }
};

int main() {
    string s1 = "oatzzffqpnwcxhejzjsnpmkmzngneo";
    string s2 = "acegneonzmkmpnsjzjhxwnpqffzzto";
    Solution sol;
    cout << sol.isScramble(s1, s2);
    cout << endl;
    return 0;
}
