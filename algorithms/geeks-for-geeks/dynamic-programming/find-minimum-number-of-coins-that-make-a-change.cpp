// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(M*V), memory: O(M*V)
    int minCoins2(int coins[], int M, int V)
    {
        int dp[M][V + 1];
        int i = 0;
        while(i < M) {
            dp[i][0] = 0;
            int j = 1;
            while(j < V + 1) {
                if (i == 0) {
                    if (j % coins[i] == 0) {
                        dp[i][j] = j / coins[i];
                    } else {
                        dp[i][j] = INT_MAX;
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j - coins[i] > -1 && dp[i][j - coins[i]] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i]]);
                    }
                }
                j++;
            }
            i++;
        }
        return dp[M - 1][V] == INT_MAX ? -1 : dp[M - 1][V];
    }

    // time: O(M*V), memory: O(V)
    int minCoins(int coins[], int M, int V) {
        int dp[V + 1];
        memset(dp, -1, sizeof(dp));
        int i = 0;
        while(i < M) {
            if (coins[i] < V + 1) {
                dp[coins[i]] = 1;
            }
            int j = 0;
            while(j < V + 1) {
                if (dp[j] != -1) {
                    int add = j + coins[i];
                    if (add < V + 1) {
                        if (dp[add] == -1) {
                            dp[add] = 1 + dp[j];
                        } else {
                            dp[add] = min(dp[add], 1 + dp[j]);
                        }
                    }
                }
                j++;
            }
            i++;
        }
        return dp[V];
    }
};

//{ Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
            cin >> coins[i];


        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";

    }
    return 0;
}

// } Driver Code Ends
