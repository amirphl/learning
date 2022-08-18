// https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    vector<int> printUnsorted(int arr[], int n) {
        int i = 0, s = -1, e = -1;
        while(i < n - 1) {
            if (arr[i] > arr[i + 1]) {
                s = i;
                break;
            }
            i++;
        }
        if (i == n - 1) {
            return {0, 0};
        }
        i = n - 1;
        while(i > 0) {
            if (arr[i - 1] > arr[i]) {
                e = i;
                break;
            }
            i--;
        }
        int minimum = arr[s], maximum = arr[e];
        i = s;
        while(i <= e) {
            minimum = min(minimum, arr[i]);
            maximum = max(maximum, arr[i]);
            i++;
        }
        i = s - 1;
        while(arr[i] > minimum && i >= 0) {
            i--;
        }
        s = i + 1;
        i = e + 1;
        while(arr[i] < maximum && i < n) {
            i++;
        }
        e = i - 1;
        return {s, e};
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
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends
