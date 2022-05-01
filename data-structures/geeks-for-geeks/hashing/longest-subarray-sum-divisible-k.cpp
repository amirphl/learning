// https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int rem(int n, int k) {
        // this was the problem, it was returning negative number.
        return ((n < 0) ? k - (-n % k) : n) % k;
    }

    // time: O(n), memory: o(n + k)
	int longSubarrWthSumDivByK(int arr[], int n, int k) {
	    int cum[n];
        // we can also use an array of size k
	    unordered_map<int, int> m;
        cum[0] = arr[0];
        int idx = rem(arr[0], k);
        int max = (idx == 0) ? 1 : 0;
        m[idx] = 0;

	    for(int i = 1; i < n; i++) {
	        cum[i] = cum[i - 1] + arr[i];
	        if (rem(cum[i], k) == 0) {
	            max = i + 1;
	        }
	        if (m.find(rem(cum[i], k)) == m.end()) {
	            m[rem(cum[i], k)] = i;
	        }
	    }

        for(int i = 0; i < n; i++) {
            idx = rem(cum[i], k);
            if (max < i - m[idx]) {
                max = i - m[idx];
            }
        }

        return max;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends
