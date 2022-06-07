// https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find minimum time required to rot all oranges.
    // time: O(m * n), memory: O(m * n)
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>>* q1 = new queue<vector<int>>;
        queue<vector<int>>* q2 = new queue<vector<int>>;
        int i = 0, j;
        while(i < n) {
            j = 0;
            while(j < m) {
                if (grid[i][j] == 2) {
                    q1 -> push({i, j});
                }
                j++;
            }
            i++;
        }
        int res = 0;
        while(! q1 -> empty()) {
            while(! q1 -> empty()) {
                int u = q1 -> front()[0];
                int v = q1 -> front()[1];
                // cout << u << " " << v << endl;
                q1 -> pop();
                vector<vector<int>> adj;
                adj.push_back({u - 1, v});
                adj.push_back({u + 1, v});
                adj.push_back({u, v - 1});
                adj.push_back({u, v + 1});
                for(auto& it: adj) {
                    if (0 <= it[0] && it[0] < n && 0 <= it[1] && it[1] < m && grid[it[0]][it[1]] == 1) {
                        grid[it[0]][it[1]] = 2;
                        q2 -> push(it);
                    }
                }
                i = 0;
                // while(i < n) {
                //     j = 0;
                //     while(j < m) {
                //         cout << grid[i][j] << " ";
                //         j++;
                //     }
                //     cout << endl;
                //     i++;
                // }
                // cout << " _____ " << endl;
            }
            if (!q2 -> empty()) {
                res++;
                queue<vector<int>>* temp = q1;
                q1 = q2;
                q2 = temp;
            }
        }
        i = 0;
        while(i < n) {
            j = 0;
            while(j < m) {
                if (grid[i][j] == 1) {
                    return -1;
                }
                j++;
            }
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
