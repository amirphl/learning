// https://leetcode.com/problems/n-queens/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> path(n);
        vector<string> pos(n);
        vector<vector<string>> res;
        int i = 0;
        while(i < n) {
            pos[i] = string(n, '.');
            i++;
        }
        find(0, n, path, pos, res);
        return res;
    }

    void find(int i, int n, vector<int>& path, vector<string>& pos, vector<vector<string>>& res) {
        vector<int> valid;
        fill_valid(i, n, valid, path);
        for(auto& j: valid) {
            // cout << i << ":" << j << " ";
            pos[i][j] = 'Q';
            path[i] = j;
            if (i < n - 1) {
                find(i + 1, n, path, pos, res);
            } else {
                res.push_back(pos);
            }
            pos[i][j] = '.';
        }
    }

    void fill_valid(int i, int n, vector<int>& valid, vector<int>& path) {
        int j = 0;
        if (i == 0) {
            valid = vector<int>(n);
            while(j < n) {
                valid[j] = j;
                j++;
            }
            return;
        }
        i = -i;
        while(j < n) {
            int c = 0;
            bool v = true;
            while(c > i) {
                int d = path[-c];
                if (j == d || j == i + d - c || j == -i + d + c) {
                    v = false;
                    break;
                }
                c--;
            }
            if (v) {
                valid.push_back(j);
            }
            j++;
        }
    }
};

int main() {
    int n = 6;
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(n);
    for(auto& v: res) {
        for(auto& s: v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
