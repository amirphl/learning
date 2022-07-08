// https://www.geeksforgeeks.org/coin-change-dp-7/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n * m), memory: O(n)
    long long int count(int S[], int m, int n) {
        vector<long long> dp(n + 1);
        int j = 0;
        while(j < m) {
            vector<long long> t(n + 1);
            int i = 0;
            while (i < n + 1) {
                if (j == 0) {
                    if (i == 0 && j == 0) {
                        t[i] = 1;
                    } else if (i < S[j] || i % S[j] != 0) {
                        t[i] = 0;
                    } else {
                        t[i] = 1;
                    }
                } else {
                    long long x = 0;
                    if (-1 < i - S[j]) {
                        x += t[i - S[j]];
                    }
                    t[i] = dp[i] + x;
                }
                // cout << t[i] << " ";
                i++;
            }
            // cout << endl;
            dp = t;
            j++;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
