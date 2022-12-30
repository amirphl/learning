// https://leetcode.com/problems/maximum-value-after-insertion/

class Solution {
public:
    string maxValue(string s, int x) {
        int n = s.length();

        if (s[0] == '-') {
            s = s.substr(1, n - 1);
            n--;

            for(int i = 0; i < n; i++) {
                if (s[i] - 48 > x) {
                    return "-" + s.substr(0, i) + to_string(x) + s.substr(i, n - i);
                }
            }

            return "-" + s + to_string(x);
        } else {
            for(int i = 0; i < n; i++) {
                if (s[i] - 48 < x) {
                    return s.substr(0, i) + to_string(x) + s.substr(i, n - i);
                }
            }

            return s + to_string(x);
        }
    }
};
