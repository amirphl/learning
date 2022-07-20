// https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(n), memory: O(n)
    int countWays(int n, int m)
    {
        int mod = 1e9 + 7;
        vector<int> dp(max(n + 1, m), 1);
        int i = m;
        while(i < n + 1) {
            dp[i] = (dp[i - 1] + dp[i - m]) % mod;
            i++;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.countWays(n, m);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends
