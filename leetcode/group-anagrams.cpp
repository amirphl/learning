// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping;

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            mapping[key].push_back(strs[i]);
        }

        vector<vector<string>> res(mapping.size());
        int i = 0;

        for(auto& it: mapping) {
            res[i] = it.second;
            i++;
        }

        return res;
    }
};
