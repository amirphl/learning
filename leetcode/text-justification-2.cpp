// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> v;

        if (words.size() == 0) {
            return v;
        }

        int j = 0;
        int curr_len = words[0].length();
        int n = words.size();

        for(int i = 1; i < n; i++) {
            if (curr_len + (i - j) + words[i].length() > maxWidth) {
                // i - 1
                int div = i - j - 1;
                int spaces = maxWidth - curr_len;
                string res = "";

                if (div == 0) {
                    res = words[j] + string(spaces, ' ');
                } else {
                    for(; j < i - 1; j++) {
                        int s = ceil((spaces * 1.0) / div);
                        res += words[j] + string(s, ' ');
                        spaces -= s;
                        div--;
                    }

                    res += words[j];
                }

                v.push_back(res);

                //
                j = i;
                curr_len = words[i].length();
            } else {
                curr_len += words[i].length();
            }
        }

        string res = "";
        for(; j < n - 1; j++) {
            res += words[j] + " ";
        }
        res += words[j];
        res += string(maxWidth - res.length(), ' ');
        v.push_back(res);

        return v;
    }
};
