// https://www.geeksforgeeks.org/smallest-element-repeated-exactly-k-times-not-limited-small-range/

//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    // time: O(n), memory: O(n)
    int findDuplicate(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        int i = 0, res = INT_MAX;
        while(i < n) {
            m[arr[i]]++;
            i++;
        }
        for(auto& x: m) {
            if (x.second == k && x.first < res) {
                res = x.first;
            }
        }
        if (res == INT_MAX) {
            res = -1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int a[n];
        for(int i = 0; i<n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.findDuplicate(a,n,k) << endl;
    }
    return 0;
}

// } Driver Code Ends
