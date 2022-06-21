// https://www.geeksforgeeks.org/maximum-sum-of-smallest-and-second-smallest-in-an-array/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution {
public:
    // time: O(n), memory: O(1)
    long long pairWithMaxSum(long long arr[], long long N)
    {
        long long i = 0;
        long long res = INT_MIN;
        while(i < N - 1) {
            res = max(res, arr[i] + arr[i + 1]);
            i++;
        }
        return res;
    }
};



// { Driver Code Starts.
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.pairWithMaxSum(a,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
