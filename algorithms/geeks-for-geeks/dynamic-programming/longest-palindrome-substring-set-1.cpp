// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n*n), memory: O(n)
    string longestPalindrome(string S) {
        int n = S.length();
        bool* dp = new bool[n];
        bool* nxt = new bool[n];
        int i = n - 1, res = 1, start = 0, end = 0;
        while(i >= 0) {
            dp[i] = true;
            // cout << dp[i][i] << " ";
            if (i + 1 < n) {
                dp[i + 1] = S[i] == S[i + 1];
                if (dp[i + 1] && res <= 2) {
                    res = 2;
                    start = i;
                    end = i + 1;
                }
                // cout << dp[i][i + 1] << " ";
            }
            int j = i + 2;
            while(j < n) {
                dp[j] = S[i] == S[j] && nxt[j - 1] == 1;
                if (dp[j] && res <= j - i + 1) {
                    res = j - i + 1;
                    start = i;
                    end = j;
                }
                // cout << dp[i][j] << " ";
                j++;
            }
            bool* temp = dp;
            dp = nxt;
            nxt = temp;
            // cout << endl;
            i--;
        }
        // TODO delete allocated arrays
        return S.substr(start, end - start + 1);
    }
};

//{ Driver Code Starts.



int main() {
    int t;
    cin>>t;
    while(t--) {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
