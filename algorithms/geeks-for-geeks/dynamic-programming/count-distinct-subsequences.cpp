// https://www.geeksforgeeks.org/count-distinct-subsequences/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int distinctSubsequences(string s)
    {
        int n = s.length();
        int i = 1, mod = 1e9 + 7;
        int dp[n];
        dp[0] = 1;
        unordered_map<char, int> pos;
        pos[s[0]] = 0;
        while(i < n) {
            dp[i] = (2 * dp[i - 1] + 1) % mod;
            if (pos.find(s[i]) != pos.end()) {
                int q = pos[s[i]];
                dp[i] -= (q == 0 ? 0 : dp[q - 1]);
                dp[i]--;
                dp[i] = (dp[i] + mod) % mod;
            }
            pos[s[i]] = i;
            i++;
        }
        return dp[n - 1] + 1;
    }
};

//{ Driver Code Starts.

int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.distinctSubsequences(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends
