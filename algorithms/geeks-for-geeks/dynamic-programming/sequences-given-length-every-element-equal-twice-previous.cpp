// https://www.geeksforgeeks.org/sequences-given-length-every-element-equal-twice-previous/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*m*log(m)), memory: O(n*m)
    int numberSequence(int m, int n) {
        int dp[n][m + 1];
        int i = 0, j = m;
        while(i < n) {
            j = m;
            while(-1 < j) {
                if (i == 0) {
                    dp[i][j] = m - j + 1;
                    j--;
                    continue;
                }
                if (j == m) {
                    if (i == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                    j--;
                    continue;
                }
                dp[i][j] = 0;
                int k = j;
                while(k * pow(2, i) <= m) {
                    dp[i][j] += dp[i - 1][2 * k];
                    k++;
                }
                j--;
            }
            i++;
        }
        // i = 0;
        // while(i < n) {
        //     j = 0;
        //     while(j <= m) {
        //         cout << dp[i][j] << " ";
        //         j++;
        //     }
        //     cout << endl;
        //     i++;
        // }
        return dp[n - 1][1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) {
        int m, n;
        cin>>m>>n;

        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
