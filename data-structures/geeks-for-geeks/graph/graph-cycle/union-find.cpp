// https://www.geeksforgeeks.org/union-find/
// https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge two nodes a and b.
    void union_(int x, int y, int par[], int rank1[]) 
    {
        find(par, x);
        find(par, y);
        if (rank1[par[x]] > rank1[par[y]]) {
            par[par[y]] = par[x];
        } else if (rank1[par[x]] < rank1[par[y]]) {
            par[par[x]] = par[y];
        } else {
            par[par[x]] = par[y];
            rank1[par[y]]++;
        }
    }

    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        return find(par, x) == find(par, y);
    }

    int find(int par[], int x) {
        if (par[x] != x) {
            par[x] = find(par, par[x]);
        }
        return par[x];
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends

