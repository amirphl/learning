// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    const int mod = 1e9 + 7;

    // TLE
    int countPaths(int n, vector<vector<int>>& roads) {
        if (n == 1) {
            return 0;
        }

        const int dest = n - 1;

        // sort(roads.begin(), roads.end());
        // int start[n];
        // memset(start, -1, sizeof(start));
        // start[roads[0][0]] = 0;

        // for(int i = 1; i < roads.size(); i++) {
        //     if (roads[i][0] != roads[i - 1][0]) {
        //         start[roads[i][0]] = i;
        //     }
        // }

        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < roads.size(); i++) {
            int s = roads[i][0];
            int d = roads[i][1];
            int c = roads[i][2];
            adj[s].push_back({d, c});
            adj[d].push_back({s, c});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        pq.push({0, 0});
        vis[0] = 1;
        int cost = INT_MIN;

        while(!pq.empty()) {
            int curr_cost = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            // if (start[curr_node] == -1) {
            //     continue;
            // }

            bool found_dest = 0;

            // for(int i = start[curr_node]; i < roads.size() && roads[i][0] == curr_node; i++) {
            for(auto& it: adj[curr_node]) {
                // int neigh = roads[i][1];
                int neigh = it.first;

                if (!vis[neigh]) {
                    // cost = curr_cost + roads[i][2];
                    cost = curr_cost + it.second;

                    if (neigh == dest) {
                        found_dest = true;
                        break;
                    }

                    pq.push({cost, neigh});
                    vis[neigh] = 1;
                }
            }

            if (found_dest) {
                break;
            }
        }

        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        count(adj, vis, 0, n - 1, 0, cost, cnt);

        return cnt;
    }

    void count(vector<vector<pair<int, int>>>& adj, bool vis[], int src, const int dst, int c_cost, const int t_cost, int& cnt) {
        if (vis[src] || c_cost > t_cost) {
            return;
        }

        if (c_cost == t_cost) {
            if (src == dst) {
                cnt = (cnt + 1) % mod;
            }
            return;
        }

        vis[src] = 1;

        for(auto& it: adj[src]) {
            int neigh = it.first;
            int r_cost = it.second;
            count(adj, vis, neigh, dst, c_cost + r_cost, t_cost, cnt);
        }

        vis[src] = 0;
    }
};
