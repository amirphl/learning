// https://www.geeksforgeeks.org/find-sum-non-repeating-distinct-elements-array/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Find the sum of all non-repeated elements
    // in an array
    // time: O(nlogn), memory: O(1)
    int findSum(int arr[], int n) {
        sort(arr, arr + n);
        int i = 1, res = 0, elem = arr[0];
        while(i < n) {
            if (arr[i] != arr[i - 1]) {
                res += elem;
                elem = arr[i];
            }
            i++;
        }
        res += elem;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
