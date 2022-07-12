// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*m), memory: O(1)
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int i = n - 1, res = 0;
        while(0 <= i) {
            int j = m - 1;
            while(0 <= j) {
                if (i != n - 1 && j != m - 1 && mat[i][j] != 0) {
                    mat[i][j] = 1 + min({mat[i + 1][j], mat[i][j + 1], mat[i + 1][j + 1]});
                }
                res = max(res, mat[i][j]);
                j--;
            }
            i--;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0; i < n*m; i++)
            cin>>mat[i/m][i%m];

        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
