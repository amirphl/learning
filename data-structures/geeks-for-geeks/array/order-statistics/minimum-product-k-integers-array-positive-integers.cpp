// https://www.geeksforgeeks.org/minimum-product-k-integers-array-positive-integers/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // time: O(nlogn), memory: O(1)
    int minProduct(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int i = 0, mod = 1e9 + 7;
        uint64_t res = 1;
        while(i < k) {
            res = (res * arr[i]) % mod;
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cin>>k;
        Solution ob;
        cout<<ob.minProduct(arr, n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
