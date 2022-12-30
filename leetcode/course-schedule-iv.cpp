// https://leetcode.com/problems/course-schedule-iv/

class Solution {
public:
    // not works
    // solution using topological sorting
    vector<bool> checkIfPrerequisite2(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n, vector<int>());

        for(int i = 0; i < pre.size(); i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vector<bool> visited(n, false);
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(i, visited, adj, ans);
        }

        reverse(ans.begin(), ans.end());

        unordered_map<int, int> loc;
        for(int i = 0; i < ans.size(); i++) {
            loc[ans[i]] = i;
        }

        int m = queries.size();
        vector<bool> res(m);
        for(int i = 0; i < m; i++) {
            res[i] = loc[queries[i][0]] < loc[queries[i][1]];
        }

        return res;
    }

    void dfs(int v, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& ans) {
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                dfs(u, visited, adj, ans);
            }
        }

        ans.push_back(v);
    }

    // transitive closure
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n, vector<int>());

        for(int i = 0; i < pre.size(); i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vector<vector<bool>> tr(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            stack<int> s;
            visited[i] = 1;
            s.push(i);

            while(!s.empty()) {
                int v = s.top();
                s.pop();

                for (int u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = 1;
                        s.push(u);
                        tr[i][u] = 1;
                    }
                }
            }
        }

        int m = queries.size();
        vector<bool> res(m);
        for(int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            res[i] = tr[a][b];
        }

        return res;
    }
};
