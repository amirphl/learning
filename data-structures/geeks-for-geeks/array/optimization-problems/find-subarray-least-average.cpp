// https://www.geeksforgeeks.org/find-subarray-least-average/
// TODO(amirphl) What about subsets, not subarrays?

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	// time: O(n), memory: O(1)
	int least_average(vector<int>arr, int k)
	{
	    int curr = 0;

	    for (int i = 0; i < k; i++)
	        curr += arr[i];

        int index = 0;
        int min = curr;

	    for (int i = 1; i < arr.size() - k + 1; i++)
	    {
	        curr = curr + arr[i + k - 1] - arr[i - 1];
	        if (curr < min)
	        {
	            min = curr;
	            index = i;
	        }
	    }
        return index + 1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.least_average(nums, k);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends
