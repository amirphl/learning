// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
public:
    int n, m;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int m = e.size();
        this -> n = n;
        this -> m = m;

        vector<set<int>> v(n);
        vector<vector<int>> res(n);

        if (m == 0) {
            return res;
        }

        bool vis[n];
        int index[n];
        memset(vis, 0, sizeof(vis));
        memset(index, -1, sizeof(index));
        index[e[0][1]] = 0;

        for(int i = 1; i < m; i++) {
            // cout << e[i][0] << "," << e[i][1] << " ";
            if (e[i][1] != e[i - 1][1]) {
                index[e[i][1]] = i;
            }
        }

        for(int i = 0; i < m; i++) {
            int src = e[i][1];

            if (!vis[src]) {
                dfs(e, v, vis, index, src);
            }
        }

        for(int i = 0; i < n; i++) {
            res[i] = vector<int>(v[i].begin(), v[i].end());
        }

        return res;
    }

    void dfs(vector<vector<int>>& e, vector<set<int>>& v, bool vis[], int index[], int src) {
        if (vis[src]) {
            return;
        }

        vis[src] = 1;

        for(int j = index[src]; j != -1 && j < m && e[j][1] == src; j++) {
            int neigh = e[j][0];
            // cout << src << ":" << neigh << endl;
            dfs(e, v, vis, index, neigh);
            v[src].insert(v[neigh].begin(), v[neigh].end());
            v[src].insert(neigh);
        }
    }
};
