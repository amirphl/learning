// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  const int INF = std::numeric_limits<int>::max();
  const int MOD = 1e9 + 7;

  // TLE
  int countRestrictedPaths(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
    int src, dst, w;

    for (auto &e : edges) {
      src = e[0];
      dst = e[1];
      w = e[2];
      adj[src].push_back({dst, w});
      adj[dst].push_back({src, w});
    }

    vector<int> dist(n + 1, INF);
    dijkstra(adj, dist, n);

    vector<int> dp(n + 1, -1);
    // vector<int> path(2 * 1e4);
    vector<int> path;

    return dfs(adj, dist, dp, path, 1, -1, 0);
  }

  int dfs(const vector<vector<pair<int, int>>> &adj, const vector<int> &dist,
          vector<int> &dp, vector<int> &path, int z, int prev_z, int level) {
    int n = dist.size() - 1;
    // path[level] = z;

    if (dp[z] != -1) {
      return dp[z];
    }

    int sum = 0;

    for (auto &p : adj[z]) {
      int next_z = p.first;

      if (next_z == n) {
        sum = (sum + 1) % MOD;

        // for (int i = 0; i <= level; i++) {
        //   cout << path[i] << " --> ";
        // }
        // cout << next_z << endl;
      } else if (dist[z] > dist[next_z]) {
        int temp = dfs(adj, dist, dp, path, next_z, z, level + 1);
        sum = (sum + temp) % MOD;
      }
    }

    return dp[z] = sum;
  }

  void dijkstra(const std::vector<std::vector<std::pair<int, int>>> &graph,
                std::vector<int> &distance, int start) {
    int n = graph.size() - 1; // Number of nodes in the graph
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    distance[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
      int dist = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      // Skip nodes that were already visited with a shorter distance
      if (dist > distance[node])
        continue;

      // Traverse all neighbors of the current node
      for (const auto &neighbor : graph[node]) {
        int neighbor_node = neighbor.first;
        int edge_weight = neighbor.second;
        int new_dist = distance[node] + edge_weight;

        if (new_dist < distance[neighbor_node]) {
          distance[neighbor_node] = new_dist;
          pq.emplace(new_dist, neighbor_node);
        }
      }
    }

    // Output the shortest distances from node `start` to all other nodes
    // for (int i = 1; i <= n; ++i) {
    //  std::cout << "Shortest distance from " << start << " to " << i
    //            << " is: " << distance[i] << std::endl;
    //}
  }
};

int main() {
  int n = 5;
  vector<vector<int>> edges{{1, 2, 3}, {1, 3, 3}, {2, 3, 1}, {1, 4, 2},
                            {5, 2, 2}, {3, 5, 1}, {5, 4, 10}};
  Solution sol;
  cout << sol.countRestrictedPaths(n, edges) << endl;
  edges = {{1, 3, 1}, {4, 1, 2}, {7, 3, 4}, {2, 5, 3},
           {5, 6, 1}, {6, 7, 2}, {7, 5, 3}, {2, 6, 4}};
  n = 7;
  cout << sol.countRestrictedPaths(n, edges) << endl;
  edges = {{2, 4, 5}, {3, 4, 2}, {2, 1, 3}, {3, 1, 3}, {4, 6, 5},
           {5, 1, 9}, {1, 4, 3}, {2, 6, 5}, {5, 6, 5}, {5, 3, 8},
           {1, 6, 6}, {3, 2, 8}, {5, 2, 8}};
  n = 6;
  cout << sol.countRestrictedPaths(n, edges) << endl;
}
