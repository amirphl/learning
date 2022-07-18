// https://www.geeksforgeeks.org/printing-matrix-chain-multiplication-a-space-optimized-solution/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*n*n), memory: O(n*n)
    // This is the space optimized solution: merged pos[][] into dp[][]
    string matrixChainOrder(int arr[], int n) {
        vector<vector<int>> dp(n, vector<int>(n));
        int i = n - 2;
        while(i >= 0) {
            dp[i][i] = 0;
            // cout << i << ":" << i << ":" << 0 << " ";
            int j = i + 1;
            while(j < n - 1) {
                dp[i][j] = INT_MAX;
                int k = i;
                while(k < j) {
                    int num = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                    if (num < dp[i][j]) {
                        dp[i][j] = num;
                        dp[j][i] = k;
                    }
                    k++;
                }
                // cout << i << ":" << j << ":" << dp[i][j] << " ";
                j++;
            }
            // cout << endl;
            i--;
        }
        char start = 'A';
        return construct(0, n - 2, start, dp);
    }

    string construct(int i, int j, char& nxt, vector<vector<int>>& dp) {
        int k = dp[j][i];
        // cout << i << " " << j << " " << k << endl;

        if (i == j) {
            string res = string(1, nxt);
            nxt++;
            return res;
        }
        if (i + 1 == j) {
            string res = "(" + string(1, nxt) + string(1, nxt + 1) + ")";
            nxt += 2;
            return res;
        }
        string left = "(" + construct(i, k, nxt, dp);
        string right = construct(k + 1, j, nxt, dp) + ")";
        return  left + right;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int p[n];
        for(int i = 0; i < n; i++)
            cin>>p[i];

        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
