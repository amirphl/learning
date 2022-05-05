// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
// https://www.geeksforgeeks.org/iterative-depth-first-traversal/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    // time: O(|V| + |E|), memory: O(|V|)
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        unordered_set<int> set;
        stack<int> sta;
        sta.push(0);

        while(!sta.empty()) {
            int u = sta.top();
            sta.pop();
            if (set.find(u) != set.end()) {
                    continue;
            }
            res.push_back(u);
            set.insert(u);
            for(auto it = adj[u].rbegin(); it != adj[u].rend(); it++) {
                if (set.find(*it) == set.end()) {
                    sta.push(*it);
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
