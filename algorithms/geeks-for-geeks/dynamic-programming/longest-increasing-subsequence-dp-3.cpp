// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    // time: O(n*n), memory: O(n)
    int longestSubsequence(int n, int arr[])
    {
        int dp[n];
        dp[0] = 1;
        int i = 0, j;
        while(++i < n) {
            j = -1;
            dp[i] = 1;
            while(++j <= i)
                dp[i] = max(dp[i], (arr[j] < arr[i]) ? dp[j] + 1 : INT_MIN);
        }
        return *max_element(dp, dp + n);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];

        //inserting elements to the array
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends
