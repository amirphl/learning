// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
public:
    int n, m;
    // TLE
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        int m = e.size();
        this -> n = n;
        this -> m = m;

        vector<vector<int>> adj(n);

        for(int i = 0; i < m; i++) {
            adj[e[i][1]].push_back(e[i][0]);
        }

        bitset<1000> v[n];
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < m; i++) {
            dfs(adj, v, vis, e[i][1]);
        }

        vector<vector<int>> res(n);
        bitset<1000> one = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 1000; j++) {
                if ((v[i] & one) == 1) {
                    res[i].push_back(j);
                }
                v[i] = v[i] >> 1;
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& adj, bitset<1000> v[], bool vis[], int src) {
        if (vis[src]) {
            return;
        }

        vis[src] = 1;
        bitset<1000> b = 0;

        for(auto& neigh: adj[src]) {
            // cout << src << ":" << neigh << endl;
            dfs(adj, v, vis, neigh);
            b |= v[neigh];
            b[neigh] = 1;
        }

        v[src] = b;
    }
};
