// https://www.geeksforgeeks.org/edit-distance-dp-5/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*m), memory: O(m)
    int editDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        int* dp = new int[m];
        int* prv = new int[m];
        int i = 0;
        while(i < n) {
            int j = 0;
            while(j < m) {
                if (s[i] == t[j]) {
                    dp[j] = min({
                        i > 0 && j > 0 ? prv[j - 1] : INT_MAX,
                        i > 0 && j == 0 ? i : INT_MAX,
                        i == 0 && j > 0 ? j : INT_MAX,
                        i == 0 && j == 0 ? 0 : INT_MAX
                    });
                } else {
                    if (i == 0 && j == 0) {
                        dp[j] = 0;
                    } else if (i > 0 && j > 0) {
                        dp[j] = min({prv[j - 1], prv[j], dp[j - 1]});
                    } else if (i == 0) {
                        dp[j] = min({j, dp[j - 1]});
                    } else {
                        dp[j] = min({i, prv[j]});
                    }
                    dp[j]++;
                }
                j++;
            }
            int* temp = dp;
            dp = prv;
            prv = temp;
            i++;
        }
        // TODO delete dp[], prv[]
        return prv[m - 1];
    }

    int editDistance1(string s, string t) {
        unordered_map<string, int> dp;
        return editDistanceRec(&s, &t, dp);
    }

    int editDistanceRec(string* s, string* t, unordered_map<string, int>& dp) {
        string key = *s + '#' + *t;

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int n = s -> length();
        int m = t -> length();

        if (m < n) {
            string* temp = s;
            s = t;
            t = temp;
            int k = n;
            n = m;
            m = k;
        }

        if (n == 0) {
            dp[key] = m;
            return m;
        }

        int i = 0;
        int i_prime = 0;
        while(i < n && i_prime < m && s -> at(i) == t -> at(i_prime)) {
            i++;
            i_prime++;
        }
        if (i == n) {
            dp[key] = m - n;
            return m - n;
        }

        int j = n - 1;
        int j_prime = m - 1;
        while(j >= i && j_prime >= i_prime && s -> at(j) == t -> at(j_prime)) {
            j--;
            j_prime--;
        }
        if (j <= i) {
            dp[key] = j_prime - i_prime + 1;
            return j_prime - i_prime + 1;
        }

        string sub_s = sub_s = s -> substr(i, j - i + 1);
        string sub_t;
        if (j - i + 1 + 1 == j_prime - i_prime + 1) {
            sub_t = t -> substr(i_prime + 1, j_prime - i_prime);
        } else {
            sub_t = t -> substr(i_prime + 1, j_prime - i_prime - 1);
        }

        dp[key] = 2 + editDistanceRec(&sub_s, &sub_t, dp);
        return dp[key];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
