// https://www.geeksforgeeks.org/find-closest-number-array/

//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(logn), memory: O(1)
    int findClosest(int arr[], int n, int target)
    {
        int index = lower_bound(arr, arr + n, target) - arr;
        if (index == n) {
            return arr[n - 1];
        }
        if (index == 0) {
            return arr[0];
        }
        return arr[index] - target <= target - arr[index - 1] ? arr[index] : arr[index - 1];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends
