// https://leetcode.com/problems/check-if-a-string-can-break-another-string/

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n = s1.length();

        bool is_s1_break_s2 = true;
        bool is_s2_break_s1 = true;

        for(int i = 0; i < n; i++) {
            if (s1[i] < s2[i]) {
                is_s1_break_s2 = false;
            }
            if (s2[i] < s1[i]) {
                is_s2_break_s1 = false;
            }
        }

        return is_s1_break_s2 || is_s2_break_s1;
    }
};
