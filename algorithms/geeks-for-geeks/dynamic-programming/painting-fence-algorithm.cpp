// https://www.geeksforgeeks.org/painting-fence-algorithm/

// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    long long countWays(int n, int k) {
        int rem = 1e9 + 7;
        long long dp[n];
        long long T[n];
        long long S[n];
        T[0] = 1;
        T[1] = k;
        T[2] = k * (k - 1);
        S[0] = 1;
        S[1] = k * (k - 1);
        S[2] = k * k * (k - 1);
        dp[0] = k;
        dp[1] = k * k;
        dp[2] = k * k * k - k;
        int i = 3;
        while(i < n) {
            T[i] = ((T[i - 2] + S[i - 2]) * (k - 1)) % rem;
            S[i] = (T[i - 2] * (k - 1) * (k - 1) + S[i - 2] * (k - 1) * k) % rem;
            dp[i] = (T[i] + S[i]) % rem;
            i++;
        }
        return dp[n - 1];
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.countWays(n,k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
