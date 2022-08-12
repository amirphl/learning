// https://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(logn), memory: O(1)
    int findMaximum(int arr[], int n) {
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if (i + 1 == j) {
                return max(arr[i], arr[j]);
            }
            int mid = (i + j) / 2;
            if (arr[mid - 1] <= arr[mid]) {
                i = mid;
            } else {
                j = mid - 1;
            }
        }
        return arr[i];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
