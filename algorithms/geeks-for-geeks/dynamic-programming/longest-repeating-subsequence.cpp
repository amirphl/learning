// https://www.geeksforgeeks.org/longest-repeating-subsequence/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*n), memory: O(n*n)
    int LongestRepeatingSubsequence(string str) {
        int n = str.length();
        int dp[n][n];
        int i = 0, res = 0;
        while(i < n) {
            int j = 0;
            while(j < n) {
                if (str[i] == str[j]) {
                    dp[i][j] = (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0) + (i == j ? 0 : 1);
                } else {
                    dp[i][j] = max(j > 0 ? dp[i][j - 1] : 0, i > 0 ? dp[i - 1][j] : 0);
                }
                res = max(res, dp[i][j]);
                j++;
            }
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
