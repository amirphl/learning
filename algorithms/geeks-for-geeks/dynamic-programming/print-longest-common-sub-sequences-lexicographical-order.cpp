// https://www.geeksforgeeks.org/print-longest-common-sub-sequences-lexicographical-order/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Time Limit Exceeded
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n = s.length(), m = t.length();
        int lcs_len = 0;
        int dp[n][m][2];
        int i = 0;
        while(i < n) {
            int j = 0;
            while(j < m) {
                if (s[i] == t[j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j][0] = 1 + dp[i - 1][j - 1][0];
                        dp[i][j][1] = 0;
                    } else {
                        dp[i][j][0] = 1;
                        dp[i][j][1] = 1;
                    }
                } else {
                    if (i > 0 && j > 0) {
                        int c1 = dp[i][j - 1][0];
                        int c2 = dp[i - 1][j][0];
                        if (c1 == c2) {
                            dp[i][j][1] = 2;
                        } else if (c1 > c2) {
                            dp[i][j][1] = 3;
                        } else {
                            dp[i][j][1] = 4;
                        }
                        dp[i][j][0] = max(c1, c2);
                    } else if (j > 0) {
                        dp[i][j][0] = dp[i][j - 1][0];
                        dp[i][j][1] = 3;
                    } else if (i > 0) {
                        dp[i][j][0] = dp[i - 1][j][0];
                        dp[i][j][1] = 4;
                    } else {
                        dp[i][j][0] = 0;
                        dp[i][j][1] = 5;
                    }
                }
                lcs_len = max(lcs_len, dp[i][j][0]);
                j++;
            }
            i++;
        }
        set<string> unique;
        string lcs(lcs_len, ' ');
        stack<vector<int>> sta;
        sta.push({n - 1, m - 1, lcs_len - 1});
        while(!sta.empty()) {
            int p = sta.top()[0];
            int q = sta.top()[1];
            int r = sta.top()[2];
            // cout << p << " " << q << " " << r << endl;
            sta.pop();
            if (dp[p][q][1] == 0) {
                lcs[r] = s[p];
                if (r == 0) {
                    unique.insert(lcs);
                } else {
                    sta.push({p - 1, q - 1, r - 1});
                }
            } else if (dp[p][q][1] == 1) {
                lcs[r] = s[p];
                unique.insert(lcs);
            } else if (dp[p][q][1] == 2) {
                sta.push({p - 1, q, r});
                sta.push({p, q - 1, r});
            } else if (dp[p][q][1] == 3) {
                sta.push({p, q - 1, r});
            } else if (dp[p][q][1] == 4) {
                sta.push({p - 1, q, r});
            }
        }
        vector<string> res(unique.size());
        i = 0;
        for(set<string>::iterator it = unique.begin(); it != unique.end(); it++) {
            res[i] = *it;
            i++;
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while(T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for(auto i: ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}


// } Driver Code Ends
