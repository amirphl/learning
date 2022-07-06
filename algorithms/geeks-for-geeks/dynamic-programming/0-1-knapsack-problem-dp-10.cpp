// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    // time: O(n * w), memory: O(n * w)
    int knapSack(int W, int wt[], int val[], int n)
    {
        int dp[n][W + 1];
        int j = 0;
        while(j < W + 1) {
            dp[n - 1][j] = wt[n - 1] <= j ? val[n - 1] : 0;
            j++;
        }
        int i = 0;
        while(i < n) {
            dp[i][0] = 0;
            i++;
        }
        i = n - 2;
        while(-1 < i) {
            j = 1;
            while(j < W + 1) {
                dp[i][j] = max(wt[i] <= j ? val[i] + dp[i + 1][j - wt[i]] : INT_MIN, dp[i + 1][j]);
                j++;
            }
            i--;
        }
        return dp[0][W];
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;

        int val[n];
        int wt[n];

        //inserting the values
        for(int i=0; i<n; i++)
            cin>>val[i];

        //inserting the weights
        for(int i=0; i<n; i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;

    }
    return 0;
}  // } Driver Code Ends
