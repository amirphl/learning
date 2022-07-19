// https://www.geeksforgeeks.org/count-ofdifferent-ways-express-n-sum-1-3-4/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(n), memory: O(n)
    long long countWays(int N) {
        int mod = 1e9 + 7;
        uint64_t dp[max(N + 1, 5)];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        int i = 5;
        while(i < N + 1) {
            dp[i] = (dp[i - 1] + dp[i - 3] + dp[i - 4]) % mod;
            i++;
        }
        return dp[N] % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.countWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
