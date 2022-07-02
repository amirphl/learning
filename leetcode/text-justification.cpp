// https://leetcode.com/problems/text-justification/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(n)
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();
        while(i < n) {
            int j = i + 1, len = words[i].length();
            while(j < n && len + 1 + words[j].length() <= maxWidth) {
                len += 1 + words[j].length();
                j++;
            }
            int backup = j;
            if (i + 1 == j) {
                res.push_back(words[i] + string(maxWidth - len, ' '));
            } else {
                int k = j - i - 1;
                int spaces = maxWidth - (len - k);
                string t = words[i];
                while(0 < k) {
                    int z;
                    if (backup == n) { // handle last line
                        z = 1;
                    } else {
                        z = ceil(1.0 * spaces / k);
                    }
                    t += string(z, ' ') + words[backup - k];
                    spaces -= z;
                    k--;
                }
                if (backup == n) {
                    t += string(spaces, ' ');
                }
                res.push_back(t);
            }
            i = backup;
        }
        return res;
    }
};

int main() {
    vector<string> words = {"Extra", "spaces", "between", "words", "should", "be", "distributed", "as", "evenly", "as", "possible.", "If", "the", "number", "of", "spaces", "on", "a", "line", "does", "not", "divide", "evenly", "between", "words,", "the", "empty", "slots", "on", "the", "left", "will", "be", "assigned", "more", "spaces", "than", "the", "slots", "on", "the", "right."};
    int maxWidth = 17;
    Solution sol;
    vector<string> res = sol.fullJustify(words, maxWidth);
    for(auto& it: res) {
        cout << it << endl;
    }
    cout << endl;
    return 0;
}
