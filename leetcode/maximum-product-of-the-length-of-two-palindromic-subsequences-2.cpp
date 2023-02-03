// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
public:
    int maxProduct(string s) {
        vector<short> path_1;
        vector<short> path_2;
        int ans = 1;
        find_all_seqs(s, path_1, path_2, 0, ans);
        return ans;
    }

    void find_all_seqs(string& s, vector<short>& path_1, vector<short>& path_2, int idx, int& ans) {
        short n = s.length();
        if (idx == n) {
            if (is_pal(s, path_1) && is_pal(s, path_2)) {
                // for(int k = 0; k < path.size(); k++) {
                //     cout << path[k] << " ";
                // }
                // cout << endl;
                ans = max(ans, (int) (path_1.size() * path_2.size()));
            }
            return;
        }

        find_all_seqs(s, path_1, path_2, idx + 1, ans);
        path_1.push_back(idx);
        find_all_seqs(s, path_1, path_2, idx + 1, ans);
        path_1.pop_back();
        path_2.push_back(idx);
        find_all_seqs(s, path_1, path_2, idx + 1, ans);
        path_2.pop_back();
    }

    bool is_pal(string& s, vector<short>& v) {
        short len = v.size();
        for(short i = 0, j = len - 1; i < j; i++, j--) {
            if (s[v[i]] != s[v[j]]) {
                return false;
            }
        }

        return true;
    }
};
