// https://www.geeksforgeeks.org/count-number-ways-reach-destination-maze/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct hashFunction
{
    size_t operator()(const pair<int,
                      int> &x) const
    {
        return x.first ^ x.second;
    }
};

class Solution {
public:
    // time: O(n*m), memory: O(n*m)
    int FindWays(int n, int m, vector<vector<int>> blocked_cells) {
        int mod = 1e9 + 7;
        unordered_set<pair<int, int>, hashFunction> s;
        for(auto& pa: blocked_cells) {
            s.insert({pa[0] - 1, pa[1] - 1});
        }
        uint64_t dp[n][m];
        int i = n - 1;
        while(i >= 0) {
            int j = m - 1;
            while(j >= 0) {
                if (s.find({i, j}) == s.end()) {
                    if (i == n - 1 && j == m - 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = ((i < n - 1 ? dp[i + 1][j] : 0) + (j < m - 1 ? dp[i][j + 1] : 0)) % mod;
                    }
                } else {
                    dp[i][j] = 0;
                }
                j--;
            }
            i--;
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>>blocked_cells;
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            blocked_cells.push_back({x, y});
        }
        Solution obj;
        int ans = obj.FindWays(n, m, blocked_cells);
        cout << ans <<'\n';
    }
    return 0;
}
// } Driver Code Ends
