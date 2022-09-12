// https://www.geeksforgeeks.org/find-second-largest-element-array/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Function returns the second
    // largest elements
    // time: O(n), memory: O(1)
    int print2largest(int arr[], int n) {
        if (n < 3) {
            return -1;
        }
        int a = arr[0], b = INT_MIN;
        int i = 1;
        while(i < n && arr[i] == a) {
            i++;
        }
        if (i == n) {
            return -1;
        }
        b = arr[i];
        i++;
        if (b > a) {
            int t = b;
            b = a;
            a = t;
        }
        while(i < n) {
            if (arr[i] == a || arr[i] == b) {
                i++;
                continue;
            }
            if (arr[i] > a) {
                b = a;
                a = arr[i];
            } else if (arr[i] > b) {
                b = arr[i];
            }
            i++;
        }
        return b;
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
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
