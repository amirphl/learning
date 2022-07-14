// https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*w), memory: O(w)
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[W + 1];
        dp[0] = 0;
        int i = 1;
        while(i < W + 1) {
            int res = 0;
            int j = 0;
            while(j < N) {
                int x = i - wt[j];
                if (x >= 0) {
                    res = max(res, val[j] + dp[x]);
                }
                j++;
            }
            dp[i] = res;
            i++;
        }
        return dp[W];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0; i < N; i++)
            cin>>val[i];
        for(int i = 0; i < N; i++)
            cin>>wt[i];

        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
