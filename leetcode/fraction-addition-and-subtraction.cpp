// https://leetcode.com/problems/fraction-addition-and-subtraction/

class Solution {
public:
    string fractionAddition(string s) {
        int n = s.length();
        int lcm = 1, denum;

        for(int i = 0; i < n; i++) {
            if (s[i] == '/') {
                if (i + 2 == n) {
                    denum = s[i + 1] - '0';
                } else {
                    if (s[i + 2] == '+' || s[i + 2] == '-') {
                        denum = s[i + 1] - '0';
                    } else {
                        denum = 10;
                    }
                }
                lcm = (denum * lcm) / __gcd(denum, lcm);
            }
        }

        int top = 0, sign, num;

        for(int i = 0; i < n; i++) {
            if (s[i] == '/') {
                if (i - 2 < 0) {
                    num = s[i - 1] - '0';
                } else {
                    if (s[i - 2] == '+') {
                        num = s[i - 1] - '0';
                    } else if (s[i - 2] == '-') {
                        num = '0' - s[i - 1];
                    } else {
                        num = 10;
                        if (i - 3 >= 0 && s[i - 3] == '-') {
                            num *= -1;
                        }
                    }
                }

                if (i + 2 == n) {
                    denum = s[i + 1] - '0';
                } else {
                    if (s[i + 2] == '+' || s[i + 2] == '-') {
                        denum = s[i + 1] - '0';
                    } else {
                        denum = 10;
                    }
                }

                top += (num * lcm / denum);
            }
        }

        if (top == 0) {
            return "0/1";
        }

        int gcd = __gcd(top < 0 ? -top : top, lcm);
        top = top / gcd;
        lcm = lcm / gcd;
        // cout << top << " " << lcm << endl;

        return to_string(top) + '/' + to_string(lcm);
    }
};
