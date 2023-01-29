// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648) {
            return 0;
        }
        bool neg = x < 0;
        x = x < 0 ? -x : x;
        int res = 0;
        int d = x % 10;
        int i = 0;
        while(x > 0) {
            if (i == 9) {
                if ((d == 2 && ((res % (int) 1e8) * 10 + (x % 10) > (neg ? 147483648 : 147483647))) || d > 2) {
                    res = 0;
                    break;
                }
            }
            res = res * 10 + (x % 10);
            x = x / 10;
            i++;
        }
        return (neg ? -1 : 1) * res;
    }
};
