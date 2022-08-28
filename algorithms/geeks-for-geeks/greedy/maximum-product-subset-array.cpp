// https://www.geeksforgeeks.org/maximum-product-subset-array/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    long long int findMaxProduct(vector<int>& arr, int n) {
        int num_zero = 0;
        int num_neg = 0;
        int num_pos = 0;
        int max_of_negs = INT_MIN;
        long long int res = 1;
        int i = 0, mod = 1e9 + 7;
        while(i < n) {
            if (arr[i] != 0) {
                res = (res * arr[i]) % mod;
            }
            if (arr[i] < 0) {
                max_of_negs = max(max_of_negs, arr[i]);
                num_neg++;
            } else if (arr[i] == 0) {
                num_zero++;
            } else {
                num_pos++;
            }
            i++;
        }
        if (num_zero == 0 && num_neg == 0 && num_pos > 0) {
            return res % mod;
        }
        if (num_zero == 0 && num_neg > 0 && num_pos == 0) {
            if (num_neg == 1) {
                return res % mod; // TODO
            }
            if (num_neg % 2 == 0) {
                return res % mod;
            } else {
                return (res / max_of_negs) % mod;
            }
        }
        if (num_zero == 0 && num_neg > 0 && num_pos > 0) {
            if (num_neg % 2 == 0) {
                return res % mod;
            } else {
                return (res / max_of_negs) % mod;
            }
        }
        if (num_zero > 0 && num_neg == 0 && num_pos == 0) {
            return 0;
        }
        if (num_zero > 0 && num_neg > 0 && num_pos == 0) {
            if (num_neg == 1) {
                return 0;
            } else if (num_neg % 2 == 0) {
                return res % mod;
            } else {
                return (res / max_of_negs) % mod;
            }
        }
        if (num_zero > 0 && num_neg == 0 && num_pos > 0) {
            return res % mod;
        }
        if (num_zero > 0 && num_neg > 0 && num_pos > 0) {
            if (num_neg % 2 == 0) {
                return res % mod;
            } else {
                return (res / max_of_negs) % mod;
            }
        }
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i = 0 ; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr, n);
        cout << ans<<endl;
    }
    return 0;
}

// } Driver Code Ends
