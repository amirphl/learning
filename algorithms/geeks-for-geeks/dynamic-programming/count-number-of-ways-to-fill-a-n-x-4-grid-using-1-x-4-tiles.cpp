// https://www.geeksforgeeks.org/count-number-of-ways-to-fill-a-n-x-4-grid-using-1-x-4-tiles/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    long long int arrangeTiles(int N) {
        long long int dp[max(N + 1, 4)];
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        int i = 5;
        while(i < N + 1) {
            dp[i] = dp[i - 4] + dp[i - 1];
            i++;
        }
        return dp[N];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;

        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
