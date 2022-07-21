// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n*n*n), memory: O(1)
    void shortest_distance(vector<vector<int>>& mat) {
        int k = 0, n = mat.size();
        while(k < n) {
            int j = 0;
            while(j < n) {
                if (k == j) {
                    j++;
                    continue;
                }
                int i = 0;
                while(i < n) {
                    if (k == i) {
                        i++;
                        continue;
                    }
                    if (mat[i][k] != -1 && mat[k][j] != -1) {
                        int d = mat[i][j] == -1 ? INT_MAX : mat[i][j];
                        mat[i][j] = min(d, mat[i][k] + mat[k][j]);
                    }
                    i++;
                }
                j++;
            }
            k++;
        }
    }

    // time: O(n*n*n), memory: O(1)
    // Doesn't work for testcase:
    // 12
    // 0 4 2 1 2 9 4 8 -1 4 -1 -1
    // 9 0 3 6 2 6 2 3 6 -1 -1 3
    // 7 1 0 10 8 9 1 3 -1 7 -1 10
    // 5 1 9 0 3 -1 1 10 7 1 -1 7
    // -1 5 1 4 0 2 10 4 10 6 4 5
    // 7 8 3 7 5 0 5 1 3 5 7 2
    // 6 -1 6 1 10 7 0 10 -1 -1 7 7
    // -1 3 2 7 4 -1 4 0 10 5 6 10
    // 10 6 1 10 4 4 7 10 0 4 7 4
    // 1 1 6 8 8 9 2 10 6 0 -1 3
    // 5 9 3 -1 4 3 -1 -1 -1 3 0 1
    // 2 2 8 6 2 4 4 3 -1 3 4 0
    void shortest_distance_2(vector<vector<int>>& mat) {
        int i = 0, n = mat.size();
        while(i < n) {
            int j = 0;
            while(j < n) {
                int k = 0;
                while(k < n) {
                    if (k == i || k == j) {
                        k++;
                        continue;
                    }
                    if (mat[i][k] != -1 && mat[k][j] != -1) {
                        int d = mat[i][j] == -1 ? INT_MAX : mat[i][j];
                        mat[i][j] = min(d, mat[i][k] + mat[k][j]);
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<vector<int>>matrix(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
