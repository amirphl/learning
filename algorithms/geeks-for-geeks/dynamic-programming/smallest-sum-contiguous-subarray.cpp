// https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    int smallestSumSubarray(vector<int>& arr) {
        int n = arr.size();
        int min_seen = arr[0];
        int curr_min = arr[0];
        int i = 1;
        while(i < n) {
            curr_min = curr_min <= 0 ? curr_min + arr[i] : arr[i];
            min_seen = min(min_seen, curr_min);
            i++;
        }
        return min_seen;
    }
};


//{ Driver Code Starts.



int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        Solution ob;

        int ans = ob.smallestSumSubarray(a);

        cout<<ans<<endl;
    }
}
// } Driver Code Ends
