// https://www.geeksforgeeks.org/longest-subsequence-such-that-difference-between-adjacents-is-one/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*n), memory: O(n)
    int longestSubsequence(int n, int arr[])
    {
        int* dp = new int[n];
        int* dp2 = new int[n];
        int* dp3 = new int[n];
        int i = 0, res = 1;
        while(i < n) {
            int j = n - 1;
            while(i < j) {
                if (abs(arr[i] - arr[j]) == 1) {
                    dp[j] = max(i > 1 ? dp3[j] : 0, 1 + (i > 0 ? dp2[i] : 1));
                } else {
                    dp[j] = i > 0 ? dp2[j] : 1;
                }
                res = max(res, dp[j]);
                // cout << dp[j] << " ";
                j--;
            }
            // cout << endl;
            int* temp = dp;
            dp = dp3;
            dp3 = dp2;
            dp2 = temp;
            i++;
        }
        // delete allocated memory
        return res;
    }

    // time: O(n*n), memory: O(n*n)
    int longestSubsequence2(int n, int arr[])
    {
        int dp[n][n];
        int j = 0, res = 1;
        while(j < n) {
            int i = 0;
            while(i < j) {
                if (abs(arr[i] - arr[j]) == 1) {
                    dp[i][j] = max(i > 1 ? dp[i - 2][j] : 0, 1 + (i > 0 ? dp[i - 1][i] : 1));
                } else {
                    dp[i][j] = i > 0 ? dp[i - 1][j] : 1;
                }
                res = max(res, dp[i][j]);
                cout << dp[i][j] << " ";
                i++;
            }
            cout << endl;
            j++;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];

        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
