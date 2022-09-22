// https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
// https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // calculate the maximum sum with out adjacent
    // time: O(n), memory: O(n) - can easily reduce the memory to O(1)
    int findMaxSum(int *arr, int n) {
        if (n == 1)
            return arr[0];

        int dp[n];
        dp[0] = arr[0];
        dp[1] = std::max(arr[0], arr[1]);
        int s, u;

        for (int i = 2; i < n; i++) {
            if (dp[i - 1] == dp[i - 2]) {
                dp[i] = arr[i] + dp[i - 1];
            } else {
                dp[i] = std::max(dp[i - 1], arr[i] + dp[i - 2]);
            }
        }

        return dp[n - 1];
    }
};

// { Driver Code Starts.

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
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
