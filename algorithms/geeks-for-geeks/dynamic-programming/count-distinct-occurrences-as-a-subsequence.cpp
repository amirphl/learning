// https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    // time: O(n*m), memory: O(m)
    int subsequenceCount(string S, string T)
    {
        int mod = 1e9 + 7;
        int n = T.length();
        int m = S.length();
        if (n > m) {
            return 0;
        }
        int* nxt = new int[m];
        int* dp = new int[m];
        int i = n - 1;
        while(i >= 0) {
            int j = m - 1;
            while(j >= 0) {
                if (T[i] == S[j]) {
                    if (i < n - 1 && j < m - 1) {
                        dp[j] = (nxt[j + 1] + dp[j + 1]) % mod;
                    } else if (i == n - 1 && j == m - 1) {
                        dp[j] = 1;
                    } else if (i < n - 1) {
                        dp[j] = 0;
                    } else {
                        dp[j] = (1 + dp[j + 1]) % mod;
                    }
                } else {
                    dp[j] = (j < m - 1 ? dp[j + 1] : 0) % mod;
                }
                // cout << i << ":" << j << ":" << dp[i][j] << " ";
                j--;
            }
            int* temp = nxt;
            nxt = dp;
            dp = temp;
            // cout << endl;
            i--;
        }
        // delete arrays
        return nxt[0];
    }
};



//{ Driver Code Starts.

//  Driver code to check above method
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string tt;
        cin>>s;
        cin>>tt;

        Solution ob;
        cout<<ob.subsequenceCount(s,tt)<<endl;


    }

}
// } Driver Code Ends
