// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*n), memory: O(n)
    int cutRod(int price[], int n) {
        int dp[n];
        dp[0] = price[0];
        int i = 1;
        while(i < n) {
            int j = 0;
            int res = price[i];
            while(j < i) {
                res = max(res, dp[j] + dp[i - 1 - j]);
                j++;
            }
            dp[i] = res;
            i++;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
