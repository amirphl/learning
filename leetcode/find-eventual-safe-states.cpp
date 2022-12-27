// https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis[n];
        memset(vis, 0, sizeof(vis));

        stack<int> s;
        s.push(0);

        vector<int> safe;

        for(int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, graph, s, vis);
            }
            if (vis[i] == 2) {
                safe.push_back(i);
            }
        }

        return safe;
    }

    // 0 unvisited
    // 1 in-progress
    // 2 safe
    // 3 not safe
    void dfs(int node, vector<vector<int>>& graph, stack<int>& s, int vis[]) {
        if (vis[node] == 2 || vis[node] == 3) {
            return;
        }
        vis[node] = 1;

        for(int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];

            if (vis[neigh] == 0) {
                dfs(neigh, graph, s, vis);

                if (vis[neigh] == 3) {
                    vis[node] = 3;
                    return;
                }
            } else if (vis[neigh] == 1 || vis[neigh] == 3) {
                vis[node] = 3;
                return;
            }
        }

        vis[node] = 2;
    }
};
