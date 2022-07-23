// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n*n), memory: O(n)
    int longestPalinSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
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

//{ Driver Code Starts.

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
