// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // time: O(|V| + |E|), memory: O(|V|)
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_set<int> path;
        short visited[V] = {0};
        for(int i = 0; i < V; i++) {
            if (!visited[i]) {
                path.insert(i);
                visited[i] = 1;
                if (dfs(i, V, adj, path, visited)) {
                    return true;
                }
                path.erase(i);
            }
        }
        return false;
    }
    bool dfs(int src, int V, vector<int> adj[], unordered_set<int> &path, short visited[]) {
        for(auto it = adj[src].begin(); it != adj[src].end(); it++) {
            if (path.find(*it) != path.end()) {
                return true;
            }
            path.insert(*it);
            visited[*it] = 1;
            if (dfs(*it, V, adj, path, visited)) {
                return true;
            }
            path.erase(*it);
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
