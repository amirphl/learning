// https://www.geeksforgeeks.org/min-cost-path-dp-6/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*m), memory: O(m)
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n = Matrix.size();
        int m = Matrix[0].size();
        int* dp = new int[m];
        int* nxt = new int[m];
        int i = n - 1, res = INT_MIN;
        while(-1 < i) {
            int j = m - 1;
            while(-1 < j) {
                dp[j] = Matrix[i][j] + max({
                    i < n - 1 && j > 0     ? nxt[j - 1] : 0,
                    i < n - 1 ? nxt[j] : 0,
                    i < n - 1 && j < m - 1 ? nxt[j + 1] : 0
                });
                if (i == 0) {
                    res = max(res, dp[j]);
                }
                j--;
            }
            int* temp = dp;
            dp = nxt;
            nxt = temp;
            i--;
        }
        // TODO delete arrays
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0; i < N*N; i++)
            cin>>Matrix[(i/N)][i%N];

        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
