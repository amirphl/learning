// https://www.geeksforgeeks.org/count-possible-paths-two-vertices/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    // time: O(N!), memory > O(V)
    int countPaths(int V, vector<int> adj[], int src, int dst) {
        unordered_set<int> s;
        s.insert(src);
        return countPathsRec(V, adj, src, dst, s);
        s.erase(src);
    }
    int countPathsRec(int V, vector<int> adj[], int src, int dst, unordered_set<int> &s) {
        // cout << src << " " << dst << endl;
        if (src == dst) {
            return 1;
        }
        int sum = 0;
        for(auto it = adj[src].begin(); it != adj[src].end(); it++) {
            if (s.find(*it) == s.end()) {
                s.insert(*it);
                sum += countPathsRec(V, adj, *it, dst, s);
                s.erase(*it);
            }
        }
        return sum;
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends
