// https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/

// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    // time: O(n), memory: O(n)
    // We can simply track the minimum and reduce memory usage to O(1)
    int minSwap(int arr[], int n, int k) {
        int m = 0;

        for (int i = 0; i < n; i++)
            if (arr[i] <= k)
                m++;

        int u = n - m + 1;
        int dp[u];
        dp[0] = 0;

        for (int i = 0; i < m; i++)
            if (arr[i] > k)
                dp[0]++;

        int min_swap = dp[0];

        for (int i = 1; i < u; i++) {
            dp[i] = dp[i - 1];

            if(arr[i - 1] > k)
                dp[i]--;

            if(arr[i + m - 1] > k)
                dp[i]++;

            if(dp[i] < min_swap)
                min_swap = dp[i];
        }

        return min_swap;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends
