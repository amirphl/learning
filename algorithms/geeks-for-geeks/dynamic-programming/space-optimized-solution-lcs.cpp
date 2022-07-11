// https://www.geeksforgeeks.org/space-optimized-solution-lcs/
// https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n*m), memory: O(n)
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int* dp = new int[n];
        int* prv = new int[n];
        int j = 0;
        while(j < m) {
            int i = 0;
            while(i < n) {
                if (s1[i] == s2[j]) {
                    dp[i] = 1 + (i > 0 && j > 0 ? prv[i - 1] : 0);
                } else {
                    dp[i] = max(i > 0 ? dp[i - 1] : 0, j > 0 ? prv[i] : 0);
                }
                i++;
            }
            int* temp = prv;
            prv = dp;
            dp = temp;
            j++;
        }
        // delete[] dp;
        // delete[] prv;
        return prv[n - 1];
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    Solution sol;
    cout << sol.longestCommonSubsequence(s1, s2) << endl;

    return 0;
}
