// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*k), memory: O(n)
    int nCr(int n, int k) {
        if (k > n) {
            return 0;
        }
        vector<uint64_t> dp(n);
        int i = 0, j = 0, rem = 1e9 + 7;
        while(i < n) {
            dp[i] = i + 1;
            i++;
        }
        i = 1;
        while(i < k) {
            vector<uint64_t> temp(n);
            temp[i] = 1;
            j = i + 1;
            while(j < n) {
                temp[j] = (temp[j - 1] + dp[j - 1]) % rem;
                // cout << " " << dp[i][j] << " ";
                j++;
            }
            dp = temp;
            // cout << endl;
            i++;
        }
        return dp[n - 1] % rem;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, r;
        cin>>n>>r;

        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
