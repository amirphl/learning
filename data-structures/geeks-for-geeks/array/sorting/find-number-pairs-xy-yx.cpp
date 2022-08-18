// https://www.geeksforgeeks.org/find-number-pairs-xy-yx/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(nlogn), memory: O(n)
    long long countPairs(int X[], int Y[], int n, int m) {
        sort(X, X + n);
        double Z[m];
        int i = 0;
        long long count = 0;
        while(i < m) {
            if (Y[i] == 1) {
                Z[i] = INT_MAX;
            } else {
                Z[i] = Y[i] * 1.0 / log2(Y[i]);
            }
            i++;
        }
        sort(Z, Z + m);
        i = 0;
        while(i < n) {
            if (X[i] != 1) {
                count += distance(upper_bound(Z, Z + m, X[i] * 1.0 / log2(X[i])), Z + m);
            }
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int X[m], Y[n];
        for (int i = 0; i < m; i++) {
            cin >> X[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> Y[i];
        }
        Solution ob;
        auto ans = ob.countPairs(X, Y, m, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
