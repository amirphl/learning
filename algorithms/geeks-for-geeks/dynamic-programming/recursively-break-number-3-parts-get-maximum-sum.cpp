// https://www.geeksforgeeks.org/recursively-break-number-3-parts-get-maximum-sum/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(n), memory: O(n)
    int maxSum(int n)
    {
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        fill(n, dp);
        return dp[n];
    }
    void fill(int i, int dp[]) {
        if (dp[i] != -1) {
            return;
        }
        if (i == 0) {
            dp[i] = 0;
            return;
        }
        int x = i / 2;
        int y = i / 3;
        int z = i / 4;
        fill(x, dp);
        fill(y, dp);
        fill(z, dp);
        x = max(x, dp[x]);
        y = max(y, dp[y]);
        z = max(z, dp[z]);
        dp[i] = x + y + z;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
