// https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    // time: O(n), memory: O(n)
    long long maxSubarraySum(int arr[], int n) {
        int pre_sum[n];
        int i = 0, s = 0;
        while(i < n) {
            s += arr[i];
            pre_sum[i] = s;
            i++;
        }
        int res = arr[0];
        int min_pre_sum = arr[0];
        i = 1;
        while(i < n) {
            res = max({res, pre_sum[i], pre_sum[i] - min_pre_sum});
            min_pre_sum = min(min_pre_sum, pre_sum[i]);
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
