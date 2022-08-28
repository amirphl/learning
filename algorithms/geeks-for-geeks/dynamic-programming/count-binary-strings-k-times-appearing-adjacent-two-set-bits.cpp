// https://www.geeksforgeeks.org/count-binary-strings-k-times-appearing-adjacent-two-set-bits/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(n*k), memory: O(n*k)
    int countStrings(int n, int k)
    {
        int mod = 1e9 + 7;
        if (k >= n) {
            return 0;
        }
        uint64_t dp[n + 1][k + 1];
        int i = 1;
        while(i < n + 1) {
            int j = 0;
            while(j < k + 1) {
                if (i == 1) {
                    if(j == 0) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 0;
                    }
                } else if (i == 2) {
                    if (j == 0) {
                        dp[i][j] = 3;
                    } else if (j == 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    if (j == 0) {
                        dp[i][j] = (dp[i - 1][j] + dp[i - 2][j]) % mod;
                    } else {
                        dp[i][j] = (dp[i - 1][j] + dp[i - 2][j] + dp[i - 1][j - 1] - dp[i - 2][j - 1] + mod) % mod;
                    }
                }
                // cout << dp[i][j] << " ";
                j++;
            }
            // cout << endl;
            i++;
        }
        return dp[n][k] % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.countStrings(n,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
