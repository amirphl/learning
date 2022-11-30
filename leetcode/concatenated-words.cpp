// https://leetcode.com/problems/concatenated-words/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, bool> con;
        unordered_set<string> u(words.begin(), words.end());
        vector<string> v;
        int i = 0;

        while(i < words.size()) {
            rec2(words[i], con, u);
            if(con[words[i]]) {
                v.push_back(words[i]);
            }
            i++;
        }

        return v;
    }

    bool rec2(string& s, unordered_map<string, bool>& con, unordered_set<string>& u) {
        if (con.find(s) != con.end()) {
            return con[s];
        }

        int i = 1;

        while(i < s.length()) {
            string w = s.substr(0, i);
            string rem = s.substr(i, s.length() - i);

            if (
                (u.find(w) != u.end() || rec2(w, con, u)) &&
                (u.find(rem) != u.end() || rec2(rem, con, u))
            ) {
                return con[s] = true;
            }

            i++;
        }

        return con[s] = false;
    }

    // using binary search
    vector<string> findAllConcatenatedWordsInADict2(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_map<string, bool> con;
        vector<string> v;
        int i = 0;

        while(i < words.size()) {
            rec(words[i], con, words);
            if(con[words[i]]) {
                v.push_back(words[i]);
            }
            i++;
        }

        return v;
    }

    int binarySearch(char ch, vector<string>& words, int low, int high) {
        if (low == high) {
            return words[low][0] == ch ? low : INT_MAX;
        }

        if (low + 1 == high) {
            if (words[low][0] == ch) {
                return low;
            }
            if (words[high][0] == ch) {
                return high;
            }
            return INT_MAX;
        }

        int mid = (low + high) / 2;

        if (words[mid][0] < ch) {
            return binarySearch(ch, words, mid, high);
        } else {
            return binarySearch(ch, words, low, mid);
        }
    }

    bool exist(string& w, vector<string>& words, int low, int high) {
        if (low == high) {
            return words[low] == w;
        }

        if (low + 1 == high) {
            return words[low] == w || words[high] == w;
        }

        int mid = (low + high) / 2;

        if (words[mid] < w) {
            return exist(w, words, mid, high);
        } else {
            return exist(w, words, low, mid);
        }
    }

    bool rec(string& s, unordered_map<string, bool>& con, vector<string>& words) {
        if (con.find(s) != con.end()) {
            return con[s];
        }

        int n = words.size();
        int i = binarySearch(s[0], words, 0, n - 1);

        while(i < words.size() && s[0] == words[i][0]) {
            string w = words[i];

            if(w.length() < s.length() && s.rfind(w, 0) == 0) {
                string rem = s.substr(w.length(), s.length() - w.length());

                if (exist(rem, words, 0, n - 1) || rec(rem, con, words)) {
                    return con[s] = true;
                }
            }

            i++;
        }

        return con[s] = false;
    }
};
