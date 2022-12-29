// https://leetcode.com/problems/construct-k-palindrome-strings/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) {
            return false;
        }

        int freq[26];
        memset(freq, 0, sizeof(freq));

        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        int odd = 0;

        for(int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
            }
        }

        return odd <= k;
    }
};
