// https://leetcode.com/problems/concatenated-words/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, vector<int>> dp;
        vector<string> v;
        vector<vector<int>> dict(26);
        for(int i = 0; i < words.size(); i++) {
            dict[words[i][0] - 'a'].push_back(i);
        }

        for(int i = 0; i < words.size(); i++) {
            string w = words[i];
            func(words, dict, dp, w);
            if (dp[w][0] == 1 && dp[w][1] != w.length()) {
                v.push_back(w);
            }
        }
        return v;
    }

    void func(vector<string>& words, vector<vector<int>>& dict, unordered_map<string, vector<int>>& dp, string& key) {
        if (dp.find(key) != dp.end()) {
            return;
        }

        int k = key.length();
        int idx = key[0] - 'a';

        for(int i = 0; i < dict[idx].size(); i++) {
            string w = words[dict[idx][i]];
            if (key.rfind(w, 0) == 0) {
                int j = w.length();
                if (j == k) {
                    dp[key] = {1, k};
                } else {
                    string rem = key.substr(j, k - j);
                    func(words, dict, dp, rem);
                    if (dp[rem][0] == 1) {
                        dp[key]  = {1, j};
                        return;
                    }
                }
            }
        }

        if (dp.find(key) == dp.end()) {
            dp[key] = {0};
        }
    }
};
