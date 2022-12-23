// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> v(numRows, "");
        bool opt = true;
        int row = 0;
        for(int i = 0; i < s.length(); i++) {
            v[row] += s[i];

            if (opt) {
                row++;

                if (row == numRows) {
                    opt = !opt;
                    row -= 2;
                }
            } else {
                row--;

                if (row == -1) {
                    opt = !opt;
                    row += 2;
                }
            }
        }

        string res = "";

        for(int i = 0; i < v.size(); i++) {
            res += v[i];
        }

        return res;
    }
};
