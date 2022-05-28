// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    // time: O(n*n), memory: O(n)
	int maxSumIS(int arr[], int n)
	{
	    int dp[n];
        dp[0] = arr[0];
        int i = 0, j;
        while(++i < n) {
            j = -1;
            dp[i] = arr[i];
            while(++j <= i)
                dp[i] = max(dp[i], (arr[j] < arr[i]) ? dp[j] + arr[i] : INT_MIN);
        }
        return *max_element(dp, dp + n);
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
