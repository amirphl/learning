// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

// Make the node as visited after pushing it to the queue, not after popping.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // time: O(V + E), memory: O(V)
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        std::queue<int> q;
        std::vector<int> vec;
        int v[V] = {}; // all zeros
        q.push(0);
        v[0] = 1;
        while(!q.empty()) {
            int top = q.front();
            // std::cout << "top " << top << std::endl;
            q.pop();
            vec.push_back(top);
            for(int i = 0; i < adj[top].size(); i++) {
                // std::cout << "next " << adj[top][i] << " " << v[adj[top][i]] << std::endl;
                if (v[adj[top][i]] == 0) {
                    q.push(adj[top][i]);
                    v[adj[top][i]] = 1;
                }
            }
        }
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
