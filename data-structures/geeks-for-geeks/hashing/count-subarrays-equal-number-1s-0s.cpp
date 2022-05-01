// https://www.geeksforgeeks.org/count-subarrays-equal-number-1s-0s/

// TODO(amirphl) first approach

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    // time: O(n), memory: O(n)
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        long long int cum[n];
        cum[0] = (arr[0] == 0) ? -1 : 1;

        unordered_map<int, int> m;
        m[cum[0]]++;

        long long int res = 0;

        for(int i = 1; i < n; i++) {
            cum[i] = cum[i - 1] + ((arr[i] == 0) ? -1 : 1);
            res += m[cum[i]];
            m[cum[i]]++;

            if (cum[i] == 0) {
                res++;
            }
        }

        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends
