// https://www.geeksforgeeks.org/distance-nearest-cell-1-binary-matrix/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct hashFunction {
        size_t operator()(const pair<int, int> &x) const {
            return x.first ^ x.second;
        }
    };

    //Function to find distance of nearest 1 in the grid for each cell.
    // This doesn't work! time limit issue!
    vector<vector<int>> nearest2(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n);
        int i = 0, j;
        while(i < n) {
            j = 0;
            res[i] = vector<int> (m);
            while(j < m) {
                bfs(i, j, grid, res);
                j++;
            }
            i++;
        }
        return res;
    }

    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& res) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, hashFunction> s;
        q.push({i, j});
        s.insert({i, j});
        while(!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            if (grid[u][v] == 1) {
                res[i][j] = abs(u - i) + abs(v - j);
                return;
            }
            vector<pair<int, int>> adj;
            // adj.push_back({u - 1, v - 1});
            adj.push_back({u - 1, v});
            // adj.push_back({u - 1, v + 1});
            adj.push_back({u, v - 1});
            adj.push_back({u, v + 1});
            // adj.push_back({u + 1, v - 1});
            adj.push_back({u + 1, v});
            // adj.push_back({u + 1, v + 1});
            int k = 0;
            while(k < adj.size()) {
                if (s.find(adj[k]) == s.end() && 0 <= adj[k].first && adj[k].first < n && 0 <= adj[k].second && adj[k].second < m) {
                    q.push(adj[k]);
                    s.insert(adj[k]);
                }
                k++;
            }
        }
        res[i][j] = INT_MAX;
    }

    // time: O(m * n), memory: O(m * n)
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n);
        vector<vector<int>> visited(n);
        queue<vector<int>> q;
        int i = 0, j;
        while(i < n) {
            j = 0;
            dist[i] = vector<int> (m, INT_MAX);
            visited[i] = vector<int> (m, 0);
            while(j < m) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
                j++;
            }
            i++;
        }
        while(!q.empty()) {
            int u = q.front()[0];
            int v = q.front()[1];
            q.pop();
            visited[u][v] = 1;
            vector<vector<int>> adj{{u, v - 1}, {u, v + 1}, {u - 1, v}, {u + 1, v}};
            // adj.push_back({u, v + 1});
            for(auto& it: adj) {
                if (0 <= it[0] && it[0] < n && 0 <= it[1] && it[1] < m && visited[it[0]][it[1]] == 0) {
                    dist[it[0]][it[1]] = min(dist[it[0]][it[1]], abs(it[0] - u) + abs(it[1] - v) + dist[u][v]);
                    q.push(it);
                }
            }
            // cout << u << " " << v << endl;
            // i = 0;
            // while(i < n) {
            //     j = 0;
            //     while(j < m) {
            //         cout << dist[i][j] << " ";
            //         j++;
            //     }
            //     cout << endl;
            //     i++;
            // }
            // cout << "_______" << endl;
        }
        return dist;
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
        vector<vector<int>> ans = obj.nearest(grid);
        for(auto i: ans) {
            for(auto j: i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends
