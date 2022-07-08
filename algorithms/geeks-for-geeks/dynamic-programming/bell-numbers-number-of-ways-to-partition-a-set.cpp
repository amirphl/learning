// https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // time: O(n*n), memory: O(n*n)
    int bellNumber(int n)
    {
        uint64_t dp[n][n], res = 0;
        int i = 0, rem = 1e9 + 7;
        while(i < n) {
            dp[i][0] = 1;
            int k = 1;
            while(k < i) {
                dp[i][k] = ((k + 1) * dp[i - 1][k] + dp[i - 1][k - 1]) % rem;
                k++;
            }
            dp[i][k] = 1; // k = i
            i++;
        }
        i = 0;
        while(i < n) {
            res += dp[n - 1][i];
            i++;
        }
        return res % rem;
    }
};


// { Driver Code Starts.



int main()
{
    Solution obj;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<obj.bellNumber(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
