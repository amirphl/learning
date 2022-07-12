// https://www.geeksforgeeks.org/maximum-sum-2-x-n-grid-no-two-elements-adjacent/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // This algorithm doesn't work because dp[i + 2] can be negative!
    int maxSum2(int n, vector<vector<int>> mat)
    {
        int dp[n];
        dp[n - 1] = max(mat[0][n - 1], mat[1][n - 1]);
        dp[n - 2] = max(mat[0][n - 2], mat[1][n - 2]);
        int i = n - 3;
        while(0 <= i) {
            dp[i] = max(mat[0][i], mat[1][i]) + dp[i + 2];
            i--;
        }
        return *max_element(dp, dp + n);
    }

    // time: O(n), memory: O(1)
    int maxSum(int n, vector<vector<int>> mat)
    {
        int sec = max(mat[0][n - 1], mat[1][n - 1]);
        if (n == 1) {
            return sec;
        }
        int fir = max({mat[0][n - 2], mat[1][n - 2], sec});
        int i = n - 3, curr;
        while(0 <= i) {
            curr = max(max(mat[0][i], mat[1][i]) + sec, fir);
            sec = fir;
            fir = curr;
            i--;
        }
        return fir;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }

        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
