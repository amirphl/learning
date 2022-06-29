// https://leetcode.com/problems/minimum-window-substring/submissions/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(n)
    string minWindow(string s, string t) {
        int n = s.length();
        int dp[n][2];

        unordered_map<char, int> freq;
        for(auto& it: t) {
            freq[it]++;
        }

        int i = 0;
        while(i < n && freq.find(s[i]) == freq.end()) {
            dp[i][0] = -1;
            dp[i][1] = 0;
            i++;
        }
        if (i < n) {
            dp[i][0] = i;
            dp[i][1] = 1;
            freq[s[i]]--;
            i++;
        }

        while(i < n) {
            char ch = s[i];
            if (freq.find(ch) == freq.end()) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            } else {
                if (freq[ch] == 0) {
                    int j = dp[i - 1][0];
                    if (s[j] == ch) {
                        j++;
                        while((freq.find(s[j]) == freq.end() || freq[s[j]] < 0)
                                && j < i) {
                            if (freq.find(s[j]) != freq.end()) {
                                freq[s[j]]++;
                            }
                            j++;
                        }
                        dp[i][0] = j;
                        dp[i][1] = dp[i - 1][1];
                    } else {
                        dp[i][0] = dp[i - 1][0];
                        dp[i][1] = dp[i - 1][1];
                        freq[ch]--;
                    }
                } else {
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1] + (freq[ch] > 0 ? 1 : 0);
                    freq[ch]--;
                }
            }
            // cout << dp[i][0] << " ";
            i++;
        }
        // cout << endl;

        i = 0;
        int len = INT_MAX, start = 0, minimum = t.length();
        while(i < n) {
            int x = i - dp[i][0] + 1;
            int y = dp[i][1];
            if (y == minimum && x < len) {
                len = x;
                start = dp[i][0];
            }
            i++;
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    cout << sol.minWindow(s, t);
    cout << endl;
    return 0;
}
