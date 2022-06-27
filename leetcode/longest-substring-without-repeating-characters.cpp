// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(n)
    int lengthOfLongestSubstring(string in) {
        if (in == "") {
            return 0;
        }

        int n = in.length();
        int dp[n];
        dp[0] = 1;
        int pos[1024];
        memset(pos, -1, sizeof(pos));
        pos[in[0]] = 0;
        int i = 1, j = 0;

        while(i < n) {
            char ch = in[i];
            if (pos[ch] == -1) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = i - pos[ch];
                j = 0;
                while(j < 1024) {
                    if (j != ch && pos[j] <= pos[ch])  {
                        pos[j] = -1;
                    }
                    j++;
                }
            }
            pos[ch] = i;
            i++;
        }

        return *max_element(dp, dp + n);
    }
};

int main() {
    string in = "jksdhjhdfuiayreubdjvdhfhdfdfaiuefjcvbdjhfeiufahjdfjkahfieufhdjfhjajdhauiehfiuadhf";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(in);
    cout << endl;
    return 0;
}
