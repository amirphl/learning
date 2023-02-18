// https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;
    unordered_map<int, int> state;

    int findPaths(int m, int n, int max_move, int row, int col) {
        this -> m = m;
        this -> n = n;

        int min_dist = min({row, m - 1 - row, col, n - 1 - col});

        if (max_move <= min_dist) {
            return 0;
        }

        return rec(max_move, row, col);
    }

    int rec(int max_move, int row, int col) {
        // cout << row << " " << col << " " << max_move << endl;
        if (max_move < 0) {
            return 0;
        }

        if (0 <= row && row < m && 0 <= col && col < n) {
            int h = hash(max_move, row, col);

            if (state.find(h) != state.end()) {
                return state[h];
            }

            int ans = 0;
            ans = (ans + rec(max_move - 1, row - 1, col)) % mod;
            ans = (ans + rec(max_move - 1, row + 1, col)) % mod;
            ans = (ans + rec(max_move - 1, row, col - 1)) % mod;
            ans = (ans + rec(max_move - 1, row, col + 1)) % mod;

            return state[h] = ans;
        } else {
            return 1;
        }
    }

    int hash(int i, int j, int k) {
        int h = i;
        h = h << 8;
        h += j;
        h = h << 8;
        h += k;

        return h;
    }
};
