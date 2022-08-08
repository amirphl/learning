// https://www.geeksforgeeks.org/number-of-paths-with-exactly-k-coins/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // time: O(n*n*k), memory: O(n*n*k)
    long long numberOfPath(int n, int coins, vector<vector<int>> arr) {
        long long dp[n][n][coins + 1];
        int i = n - 1;
        while(i >= 0) {
            int j = n - 1;
            while(j >= 0) {
                int k = 0;
                while(k <= coins) {
                    int diff = k - arr[i][j];
                    if (diff < 0) {
                        dp[i][j][k] = 0;
                    } else if (diff == 0) {
                        if (i == n - 1 && j == n - 1) {
                            dp[i][j][k] = 1;
                        } else {
                            dp[i][j][k] = 0;
                        }
                    } else {
                        dp[i][j][k] = 0;
                        if (i < n - 1) {
                            dp[i][j][k] += dp[i + 1][j][diff];
                        }
                        if (j < n - 1) {
                            dp[i][j][k] += dp[i][j + 1][diff];
                        }
                    }
                    k++;
                }
                j--;
            }
            i--;
        }
        return dp[0][0][coins];
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
