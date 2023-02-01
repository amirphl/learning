// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int next_next = s[n - 1] == '0' ? 0 : 1;

        if (n == 1) {
            return next_next;
        }

        int next, temp;
        if (s[n - 2] == '0') {
            next = 0;
        } else if (s[n - 2] == '1' || (s[n - 2] == '2' && s[n - 1] - '0' < 7)) {
            next = next_next + 1;
        } else {
            next = next_next;
        }
// cout << next_next << " " << next << endl;
        for(int i = n - 3; i >= 0; i--) {
            if (s[i] == '0') {
                next_next = next;
                next = 0;
            } else if (s[i] == '1' || (s[i] == '2' && s[i + 1] - '0' < 7)) {
                temp = next + next_next;
                next_next = next;
                next = temp;
            } else {
                next_next = next;
            }
// cout << s << " " << i << " " << next << " " << next_next << endl;
        }

        return next;
    }
};
