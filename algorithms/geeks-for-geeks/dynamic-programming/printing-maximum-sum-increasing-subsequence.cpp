// https://www.geeksforgeeks.org/printing-maximum-sum-increasing-subsequence/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*n), memory: O(n)
    vector<int> maxSumSequence(int N, int A[])
    {
        int dp[N];
        int prv[N];
        int i = 0, max_val = INT_MIN, max_idx;
        while(i < N) {
            dp[i] = A[i];
            prv[i] = -1;
            int j = 0;
            while(j < i) {
                if (A[j] < A[i]) {
                    if (dp[i] < A[i] + dp[j]) {
                        dp[i] = A[i] + dp[j];
                        prv[i] = j;
                    }
                }
                j++;
            }
            if (max_val < dp[i]) {
                max_val = dp[i];
                max_idx = i;
            }
            i++;
        }
        vector<int> res;
        while(max_idx != -1) {
            res.push_back(A[max_idx]);
            max_idx = prv[max_idx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ans = ob.maxSumSequence(N, A);
        for(auto num: ans)
            cout<<num<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
