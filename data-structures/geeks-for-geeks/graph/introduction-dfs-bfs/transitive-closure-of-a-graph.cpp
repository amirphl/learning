// https://www.geeksforgeeks.org/transitive-closure-of-a-graph/
// https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    // time: O(|V|(|V| + |E|))
    // for sprase graph: O(|V|^2)
    // for dense  graph: O(|V|^3)
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        vector<vector<int>> reach(n);
        for(int i = 0; i < n; i++) {
            reach[i].resize(n, 0);
        }
        for(int i = 0; i < n; i++) {
            dfsRec(i, i, n, graph, reach);
        }
        return reach;
    }

    void dfsRec(int src, int i, int n, vector<vector<int>> &graph, vector<vector<int>> &reach) {
        if (reach[src][i] == 1) {
            return;
        }
        reach[src][i] = 1;
        for(int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                dfsRec(src, j, n, graph, reach);
            }
        }
    }




    // time: O(V^3)
    vector<vector<int>> transitiveClosure2(int n, vector<vector<int>> graph)
    {
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++) {
            res[i].resize(n);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = (i == j) || graph[i][j];
            }
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    res[i][j] = res[i][j] || (res[i][k] && res[k][j]);
                }
            }
        }
        return res;
    }

    // my wrong solution
    vector<vector<int>> transitiveClosure3(int n, vector<vector<int>> graph)
    {
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++) {
            res[i].resize(n, -1);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                transitiveClosureRec(n, graph, i, j, res);
            }
        }
        return res;
    }
    // my wrong solution
    int transitiveClosureRec(int n, vector<vector<int>> &graph, int i, int j, vector<vector<int>> &res) {
        if (i == j || graph[i][j] == 1) {
            res[i][j] = 1;
            return 1;
        } else if (res[i][j] == -1) {
            for(int u = 0; u < n; u++) {
                if (u == j) {
                    continue;
                } else if (graph[u][j] == 1) {
                    if (res[i][u] == 1) {
                        res[i][j] = 1;
                        return 1;
                    }
                    else if (res[i][u] == -1) {
                        // cout << i << " " << u << " " << j << endl;
                        int mid = transitiveClosureRec(n, graph, i, u, res);
                        if (mid == 1) {
                            res[i][j] = 1;
                            return 1;
                        }
                    }
                }
            }
            res[i][j] = 0;
            return 0;
        } else { // res[i][j] == 0 || res[i][j] == 1
            return res[i][j];
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}  // } Driver Code Ends
