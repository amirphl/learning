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
        int target_cost = INT_MAX, cnt = 0;

        while(!pq.empty()) {
            int curr_cost = pq.top().first;
            int curr_node = pq.top().second;
            vis[curr_node] = 1;
            pq.pop();
            // cout << curr_node << " " << curr_cost << " ---> ";

            for(auto& it: adj[curr_node]) {
                int neigh = it.first;

                if (!vis[neigh]) {
                    int cost = curr_cost + it.second;

                    if (cost == target_cost) {
                        if (neigh == dest) {
                            // cout << "cnt++:" << neigh << " ";
                            cnt = (cnt + 1) % mod;
                        }
                    } else if (cost < target_cost) {
                        if (neigh == dest) {
                            // cout << "cnt=1:" << neigh << " ";
                            target_cost = cost;
                            cnt = 1;
                        } else {
                            // cout << "push :" << neigh << " ";
                            pq.push({cost, neigh});
                        }
                    }
                }
            }
            // cout << endl;
        }

        return cnt;
    }
};
