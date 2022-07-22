// https://www.geeksforgeeks.org/dice-throw-dp-30/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*m*x), memory: O(X)
    long long noOfWays(int M, int N, int X) {
        long long* prv = new long long[X + 1];
        long long* dp = new long long[X + 1];
        int i = 0;
        while(i < N) {
            int j = 0;
            while(j <= X) {
                if (j == 0) {
                    dp[j] = 0;
                } else if (i == 0) {
                    dp[j] = j <= M ? 1 : 0;
                } else {
                    dp[j] = 0;
                    int k = 1;
                    while(k <= min(j, M)) {
                        dp[j] += prv[j - k];
                        k++;
                    }
                }
                // cout << dp[i][j] << " ";
                j++;
            }
            long long* temp = dp;
            dp = prv;
            prv = temp;
            // cout << endl;
            i++;
        }
        // TODO delete arrays
        return prv[X];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;

        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
