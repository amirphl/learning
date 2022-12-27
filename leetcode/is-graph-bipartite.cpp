// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        short vis[n];
        memset(vis, 0, sizeof(vis));

        for(int j = 0; j < n; j++) {
            if (vis[j] != 0) {
                continue;
            }

            stack<int> s;
            s.push(j);
            vis[j] = 1;

            while(!s.empty()) {
                int node = s.top();
                int side = vis[node];
                s.pop();

                for(int i = 0; i < graph[node].size(); i++) {
                    int neigh = graph[node][i];

                    if (vis[neigh] == 0) {
                        vis[neigh] = (side == 1 ? 2 : 1);
                        s.push(neigh);
                    } else if (vis[neigh] == side) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
