// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*n*n), memory: O(n*n)
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];
        memset(dp, 0, sizeof(dp));
        int i = N - 2;
        while(i >= 0) {
            // cout << i << ":" << i << ":" << 0 << " ";
            int j = i + 1;
            while(j < N - 1) {
                dp[i][j] = INT_MAX;
                int k = i;
                while(k < j) {
                    int left = dp[i][k];
                    int right = dp[k + 1][j];
                    // if (i == 0 && j == 2) {
                    //     cout << arr[i] << "__" << arr[k + 1] << "__" << arr[j + 1] << " ";
                    // }
                    dp[i][j] = min(dp[i][j], left + right + arr[i] * arr[k + 1] * arr[j + 1]);
                    k++;
                }
                // cout << i << ":" << j << ":" << dp[i][j] << " ";
                j++;
            }
            // cout << endl;
            i--;
        }
        return dp[0][N - 2];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
