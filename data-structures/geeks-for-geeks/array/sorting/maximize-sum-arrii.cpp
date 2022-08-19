// https://www.geeksforgeeks.org/maximize-sum-arrii/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(1)
    int Maximize(int arr[],int n)
    {
        int mod = 1e9 + 7;
        sort(arr, arr + n);
        long long res = 0;
        int i = 0;
        while(i < n) {
            res = (res + ((i * (long long) arr[i]) % mod)) % mod;
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends
