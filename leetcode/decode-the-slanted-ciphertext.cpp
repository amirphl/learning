// https://leetcode.com/problems/decode-the-slanted-ciphertext/

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if (rows == 1) {
            return s;
        }

        int n = s.length();
        string res(n, ' ');
        int p = n / rows;
        int k = 0;

        for (int i = 0; i < p; i++) {
            for(int j = 0; j < rows && (j * p + i + j) < n; j++) {
                res[k] = s[j * p + i + j];
                k++;
            }
        }

        rtrim(res);
        return res;
    }
};
