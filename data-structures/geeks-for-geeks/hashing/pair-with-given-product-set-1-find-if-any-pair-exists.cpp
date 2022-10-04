// https://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    bool isProduct(int arr[], int n, long long x) {
        sort(arr, arr + n);
        int i = 0;
        while(i < n) {
            if (arr[i] == 0) {
                if (x == 0) {
                    return true;
                } else {
                    i++;
                    continue;
                }
            }
            if (x % arr[i] != 0) {
                i++;
                continue;
            }
            int idx = lower_bound(arr + i + 1, arr + n, x / arr[i]) - arr;
            if (idx < n && arr[idx] == x / arr[i]) {
                // cout << arr[i] << " " << x / arr[i] << endl;
                return true;
            }
            i++;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.isProduct(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
// } Driver Code Ends
