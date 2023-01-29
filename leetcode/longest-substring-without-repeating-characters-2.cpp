// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.length();
        bool visited[256];
        memset(visited, 0, sizeof(visited));

        int i = 0, j = 0;
        for(; i < n;) {
            if (visited[s[i]]) {
                // cout << j << " " << i << endl;
                ans = max(ans, i - j);
                visited[s[j]] = 0;
                j++;
            } else {
                visited[s[i]] = 1;
                i++;
            }
        }

        return max(ans, i - j);
    }
};
