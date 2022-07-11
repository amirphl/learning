// https://www.geeksforgeeks.org/lcs-longest-common-subsequence-three-strings/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

// time: O(n1*n2*n3), memory: O(n1*n2*n3)
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1][n2][n3];
    int i = 0;
    while(i < n1) {
        int j = 0;
        while(j < n2) {
            int k = 0;
            while(k < n3) {
                if (A[i] == B[j] && B[j] == C[k]) {
                    dp[i][j][k] = 1 + (i > 0 && j > 0 && k > 0 ? dp[i - 1][j - 1][k - 1] : 0);
                } else {
                    dp[i][j][k] = max({
                        i > 0 ? dp[i - 1][j][k] : 0,
                        j > 0 ? dp[i][j - 1][k] : 0,
                        k > 0 ? dp[i][j][k - 1] : 0
                    });
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return dp[n1 - 1][n2 - 1][n3 - 1];
}
