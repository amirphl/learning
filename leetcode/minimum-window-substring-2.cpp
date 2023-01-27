// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int freq[60];
        int chars[60];
        memset(freq, 0, sizeof(freq));
        memset(chars, 0, sizeof(chars));

        for(int i = 0; i < m; i++) {
            freq[t[i] - 'A']++;
            chars[t[i] - 'A']++;
        }

        int j = -1, count = m, start = 0, end = INT_MAX;

        for(int i = 0; i < n; i++) {
            if (freq[s[i] - 'A'] > 0) {
                if (j == -1) {
                    j = i;
                }
                count--;
            }
            freq[s[i] - 'A']--;
            while (count == 0) {
                if (i - j < end - start) {
                    end = i;
                    start = j;
                }
                int backup_j = j;

                j++;
                while(j <= i && chars[s[j] - 'A'] == 0) {
                    j++;
                }

                if (freq[s[backup_j] - 'A'] == 0) {
                    count++;
                }

                freq[s[backup_j] - 'A']++;
            }
        }

        return end == INT_MAX ? "" : s.substr(start, end - start + 1);
    }
};
