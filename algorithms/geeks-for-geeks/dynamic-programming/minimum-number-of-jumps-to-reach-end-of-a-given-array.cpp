// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // iterative approach
    // time: O(n), memory: O(1)
    int canReach(int arr[], int n) {
        int last_seen = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if (last_seen <= i + arr[i]) {
                last_seen = i;
            }
        }
        return last_seen == 0;
    }
    // recursive approach
    // time: O(n), memory: O(n)
    int canReach2(int A[], int N) {
        int dp[N];
        memset(dp, -1, sizeof(dp));
        int res = canReachRec(A, dp, 0, N);
        return res != INT_MAX;
    }
    int canReachRec(int arr[], int dp[], int i, int n) {
        if (i == n - 1) {
            dp[i] = 0;
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int j = arr[i];
        int res = INT_MAX;
        while(j > 0) {
            if (n <= i + j) {
                j--;
                continue;
            }
            res = min(res, canReachRec(arr, dp, i + j, n));
            j--;
        }
        dp[i] = res;
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;

        int A[N];

        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
