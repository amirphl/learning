// https://leetcode.com/problems/distinct-subsequences/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n*m), memory: O(n)
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<unsigned long int> dp(n);
        int j = m - 1;
        while(-1 < j) {
            int i = n - 1;
            unsigned long int sum = 0;
            vector<unsigned long int> temp(n);
            while(-1 < i) {
                if (s[i] == t[j]) {
                    sum += (j == m - 1) ? 1 : (i == n - 1 ? 0 : dp[i + 1]);
                }
                temp[i] = sum;
                i--;
            }
            dp = temp;
            j--;
        }
        return dp[0];
    }
};

int main() {
    string s = "rabbbit";
    string t = "rabbit";
    Solution sol;
    cout << sol.numDistinct(s, t);
    cout << endl;
    return 0;
}
