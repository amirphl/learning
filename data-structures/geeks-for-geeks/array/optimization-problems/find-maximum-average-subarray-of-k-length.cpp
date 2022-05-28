// https://www.geeksforgeeks.org/find-maximum-average-subarray-of-k-length/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // time: O(n), memory: O(1)
    int findMaxAverage(int arr[], int n, int k) {
        int sum = 0;
        int i = -1;
        while(++i < k)
            sum += arr[i];
        i = k - 2;
        int res = sum;
        int idx = 0;
        while(++i < n) {
            if (sum > res) {
                idx = i - k + 1;
                res = sum;
            }
            sum = sum - arr[i - k + 1] + arr[i + 1];
            // cout << sum << endl;
        }
        return idx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
