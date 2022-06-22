// https://leetcode.com/problems/longest-palindromic-substring/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n*n), memory: O(n*n)
    string longestPalindrome(string in) {
        int n = in.length();
        int dp[n][n][2];
        int i = 0, j;
        while(i < n) {
            dp[i][i][0] = i;
            dp[i][i][1] = i;
            i++;
        }

        i = n - 2;
        while(-1 < i) {
            j = i + 1;
            while(j < n) {
                int x = dp[i][j - 1][0];
                int y = dp[i][j - 1][1];
                int p = dp[i + 1][j][0];
                int q = dp[i + 1][j][1];
                if (y - x < q - p) {
                    x = p;
                    y = q;
                }
                dp[i][j][0] = x;
                dp[i][j][1] = y;
                if (in[i] == in[j]) {
                    if (i == j - 1) {
                        dp[i][j][0] = i;
                        dp[i][j][1] = j;
                    } else {
                        x = dp[i + 1][j - 1][0];
                        y = dp[i + 1][j - 1][1];
                        if (x == i + 1 && y == j - 1) {
                            dp[i][j][0] = i;
                            dp[i][j][1] = j;
                        }
                    }
                }
                j++;
            }
            i--;
        }

        return in.substr(dp[0][n - 1][0], dp[0][n - 1][1] - dp[0][n - 1][0] + 1);
    }
};

int main() {
    string input = "dkjfhdjkhfjghfdgdhjdjdjdfggfjdjdjdueryueryuy";
    Solution sol;
    cout << sol.longestPalindrome(input) << endl;
    return 0;
}
