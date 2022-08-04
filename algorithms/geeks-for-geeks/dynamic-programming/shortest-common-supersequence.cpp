// https://www.geeksforgeeks.org/shortest-common-supersequence/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
public:
    //Function to find length of shortest common supersequence of two strings.
    // time: O(n*m), memory: O(m)
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
        int* dp = new int[m];
        int* nxt = new int[m];
        int i = n - 1;
        while(i >= 0) {
            int j = m - 1;
            while(j >= 0) {
                if (X[i] == Y[j]) {
                    if (i < n - 1 && j < m - 1) {
                        dp[j] = nxt[j + 1] + 1;
                    } else if (i < n - 1) {
                        dp[j] = n - 1 - i + 1;
                    } else if (j < m - 1) {
                        dp[j] = m - 1 - j + 1;
                    } else {
                        dp[j] = 1;
                    }
                } else {
                    dp[j] = INT_MAX;
                    if (i < n - 1) {
                        dp[j] = min(dp[j], 1 + nxt[j]);
                    }
                    if (j < m - 1) {
                        dp[j] = min(dp[j], 1 + dp[j + 1]);
                    }
                    if (i == n - 1 && j == m - 1) {
                        dp[j] = 2;
                    }
                }
                j--;
            }
            int* t = dp;
            dp = nxt;
            nxt = t;
            i--;
        }
        // delete allocated arrays
        return nxt[0];
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    //taking total testcases
    cin >> t;
    while(t--) {
        string X, Y;
        //taking String X and Y
        cin >> X >> Y;

        //calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
    return 0;
}


// } Driver Code Ends
