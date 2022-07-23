// https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/

//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    /*You are required to complete below method */
    // time: O(n*n), memory: O(n)
    long long int countPS(string s1)
    {
        int n = s1.length(), mod = 1e9 + 7;
        long long int* dp = new long long int[n];
        long long int* nxt = new long long int[n];
        int i = n - 1;
        while(i >= 0) {
            int j = i;
            while(j < n) {
                if (i == j) {
                    dp[j] = 1;
                } else if (i + 1 == j) {
                    dp[j] = 2 + (s1[i] == s1[j] ? 1 : 0);
                } else {
                    dp[j] = ((nxt[j] + dp[j - 1] - (s1[i] == s1[j] ? -1 : nxt[j - 1])) + mod) % mod;
                }
                j++;
            }
            long long int* temp = nxt;
            nxt = dp;
            dp = temp;
            i--;
        }
        // delete[] dp;
        // delete[] prv;
        return nxt[n - 1];
    }

};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
