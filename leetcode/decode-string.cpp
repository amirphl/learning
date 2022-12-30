// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        s = '[' + s + ']';
        int i = 0;
        string res = "";
        rec(i, s, res);

        return res;
    }

    void rec(int& i, string& s, string& res) {
        i++;
        res = "";
        int times = 0, n = s.length();

        while(i < n) {
            if ('a' <= s[i] && s[i] <= 'z') {
                res += s[i];
            } else if (s[i] == '[') {
                string sub = "";
                rec(i, s, sub); // end i at ]
                int j = 0;
                times = times == 0 ? 1 : times;

                while(j < times) {
                    res += sub;
                    j++;
                }

                times = 0;
            } else if (s[i] == ']') {
                break;
            } else { // number
                times = times * 10 + s[i] - 48;
            }
            i++;
        }
    }
};
