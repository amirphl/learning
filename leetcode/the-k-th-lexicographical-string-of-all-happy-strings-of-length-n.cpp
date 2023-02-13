// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
public:
    string getHappyString(int n, int k) {
        int m = 3 * (int) pow(2, n - 1);

        if (k > m) {
            return "";
        }

        string res(n, ' ');

        if (k <= m / 3) {
            res[0] = 'a';
        } else if (k <= 2 * m / 3) {
            res[0] = 'b';
            k -= m / 3;
        } else if (k <= m) {
            res[0] = 'c';
            k -= 2 * m / 3;
        } else {
            return "";
        }

        int i = 1;
        while(i < n) {
            m /= 2;
            int j = m / 3;
            // cout << i << " " << k << " " << m << " " << res[i - 1] << endl;
            if (res[i - 1] == 'a') {
                if (k <= j) {
                    res[i] = 'b';
                } else {
                    res[i] = 'c';
                    k -= j;
                }
            } else if (res[i - 1] == 'b') {
                if (k <= j) {
                    res[i] = 'a';
                } else {
                    res[i] = 'c';
                    k -= j;
                }
            } else {
                if (k <= j) {
                    res[i] = 'a';
                } else {
                    res[i] = 'b';
                    k -= j;
                }
            }
            i++;
        }

        return res;
    }
};
