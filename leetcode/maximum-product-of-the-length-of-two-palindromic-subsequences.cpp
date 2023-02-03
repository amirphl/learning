// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
public:
    // TLE
    int maxProduct(string s) {
        int len = s.length();
        bool all_same = true;
        for(int i = 1; i < len; i++) {
            if (s[i] != s[i - 1]) {
                all_same = false;
                break;
            }
        }
        if (all_same) {
            return ceil(1.0 * len / 2) * floor(1.0 * len / 2);
        }
        vector<vector<int>> seqs;
        vector<int> path;
        find_all_seqs(s, path, seqs, 0);

        int ans = 1;
        int n = seqs.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if (disjoint(seqs, i, j)) {
                    ans = max(ans, (int)(seqs[i].size() * seqs[j].size()));
                }
            }
        }

        return ans;
    }

    void find_all_seqs(string& s, vector<int>& path, vector<vector<int>>& seqs, int idx) {
        int n = s.length();
        if (idx == n) {
            if (is_pal(s, path)) {
                // for(int k = 0; k < path.size(); k++) {
                //     cout << path[k] << " ";
                // }
                // cout << endl;
                seqs.push_back(path);
            }
            return;
        }

        find_all_seqs(s, path, seqs, idx + 1);
        path.push_back(idx);
        find_all_seqs(s, path, seqs, idx + 1);
        path.pop_back();
    }

    bool is_pal(string& s, vector<int>& v) {
        int len = v.size();
        for(int i = 0, j = len - 1; i < j; i++, j--) {
            if (s[v[i]] != s[v[j]]) {
                return false;
            }
        }

        return true;
    }

    bool disjoint(vector<vector<int>>& seqs, int i, int j) {
        unordered_set<int> us(seqs[i].begin(), seqs[i].end());
        int n = seqs[j].size();
        for(int k = 0; k < n; k++) {
            if (us.find(seqs[j][k]) != us.end()) {
                return false;
            }
        }

        return true;
    }
};
