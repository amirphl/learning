// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n * m), memory: O(n)
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        vector<int> dp(n);
        vector<int> dp2(n);
        int i = n - 1, j = m - 1, res = 0;
        while(-1 < j) {
            i = n - 1;
            while(-1 < i) {
                dp2[i] = 0;
                if (s1[i] == s2[j]) {
                    dp2[i] = 1 + (i < n - 1 && j < m - 1 ? dp[i + 1] : 0);
                }
                res = max(res, dp2[i]);
                i--;
            }
            dp = dp2;
            j--;
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends
