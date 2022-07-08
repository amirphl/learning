// https://www.geeksforgeeks.org/gold-mine-problem/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*m), memory: O(n)
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<int> dp(n);
        int i = 0, j = m - 1, res = INT_MIN;
        while(-1 < j) {
            i = 0;
            vector<int> t(n);
            while(i < n) {
                t[i] = M[i][j];
                if (j < m - 1) {
                    t[i] += max({i > 0 ? dp[i - 1] : INT_MIN, dp[i], i < n - 1 ? dp[i + 1] : INT_MIN});
                }
                res = max(res, t[i]);
                i++;
            }
            dp = t;
            j--;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cin>>M[i][j];
        }

        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
