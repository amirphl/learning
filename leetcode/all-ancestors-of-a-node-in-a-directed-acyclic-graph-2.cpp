// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
public:
    int n, m;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        int m = e.size();
        this -> n = n;
        this -> m = m;

        vector<vector<int>> adj(n);

        for(int i = 0; i < m; i++) {
            adj[e[i][1]].push_back(e[i][0]);
        }

        vector<set<int>> v(n);
        vector<vector<int>> res(n);
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < m; i++) {
            dfs(adj, v, vis, e[i][1]);
        }

        for(int i = 0; i < n; i++) {
            res[i] = vector<int>(v[i].begin(), v[i].end());
        }

        return res;
    }

    void dfs(vector<vector<int>>& adj, vector<set<int>>& v, bool vis[], int src) {
        if (vis[src]) {
            return;
        }

        vis[src] = 1;

        for(auto& neigh: adj[src]) {
            // cout << src << ":" << neigh << endl;
            dfs(adj, v, vis, neigh);
            v[src].insert(v[neigh].begin(), v[neigh].end());
            v[src].insert(neigh);
        }
    }
};
