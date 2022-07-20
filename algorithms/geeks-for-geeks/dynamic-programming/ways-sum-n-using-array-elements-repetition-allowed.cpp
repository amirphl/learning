// https://www.geeksforgeeks.org/ways-sum-n-using-array-elements-repetition-allowed/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // function to count the total
    // number of ways to sum up to 'N'
    // time: O(n*m), memory: O(n)
    int countWays(int arr[], int m, int N)
    {
        int dp[N + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        fillRec(N, dp, arr, m);
        return dp[N];
    }

    void fillRec(int i, int dp[], int arr[], int m) {
        if (dp[i] != -1) {
            return;
        }
        dp[i] = 0;
        int j = 0, mod = 1e9 + 7;
        while(j < m) {
            if (i - arr[j] >= 0) {
                fillRec(i - arr[j], dp, arr, m);
                dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
            }
            j++;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n ;
        cin>>m>>n;
        int arr[m];
        for(int i = 0; i<m; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.countWays(arr,m,n)<<endl;
    }
}
// } Driver Code Ends
