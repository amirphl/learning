// https://www.geeksforgeeks.org/largest-sum-zig-zag-sequence-in-a-matrix/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*n*n), memory: O(1)
    int zigzagSequence(int n, vector<vector<int>> M) {
        int i = n - 2;
        while(i >= 0) {
            int j = n - 1;
            while(j >= 0) {
                int temp = M[i + 1][j];
                M[i + 1][j] = INT_MIN;
                M[i][j] += *max_element(M[i + 1].begin(), M[i + 1].end());
                M[i + 1][j] = temp;
                j--;
            }
            i--;
        }
        return *max_element(M[0].begin(), M[0].end());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> M(n, vector<int>(n, -1));
        for(int i = 0; i < n*n; i++)
            cin>>M[i/n][i%n];

        Solution ob;
        cout<<ob.zigzagSequence(n, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends
