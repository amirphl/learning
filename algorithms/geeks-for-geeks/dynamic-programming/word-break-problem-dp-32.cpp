// https://www.geeksforgeeks.org/word-break-problem-dp-32/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    // time: O(n*m), memory: O(n)
    int wordBreak(string& A, vector<string>& B) {
        int dp[A.length()];
        memset(dp, -1, sizeof(dp));
        fillRec(A, B, 0, dp);
        return dp[0];
    }

    void fillRec(string& A, vector<string>& B, int i, int dp[]) {
        int n = A.length();
        int m = B.size();
        if (i == n || dp[i] != -1) {
            return;
        }
        int j = 0;
        while(j < m) {
            int sub_len = B[j].length();
            if (i + sub_len - 1 < n && A.substr(i, sub_len) == B[j]) {
                // cout << A.substr(i, sub_len) << endl;
                fillRec(A, B, i + sub_len, dp);
                if (i + sub_len == n || dp[i + sub_len] == 1) {
                    dp[i] = 1;
                    return;
                }
            }
            j++;
        }
        dp[i] = 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0; i<n; i++) {
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
