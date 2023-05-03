// https://leetcode.com/problems/knight-probability-in-chessboard/description/

class Solution {
public:
    int n;
    int KK;

    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) {
            return 1;
        }

        this -> n = n;
        this -> KK = k + 1;
        double dp[n * n * (k + 1)];
        memset(dp, -1, sizeof(dp));
        rec(row, column, k, dp);

        double res = at(row, column, k, dp);

        return res;
    }

    bool is_valid(vector<int>& point) {
        int x = point[0];
        int y = point[1];

        return 0 <= x && x < n && 0 <= y && y < n;
    }

    double at(int i, int j, int k, double dp[]) {
        return dp[(i * n * KK) + (j * KK) + k];
    }

    void set(int i, int j, int k, double val, double dp[]) {
        dp[(i * n * KK) + (j * KK) + k] = val;
    }

    void rec(int i, int j, int k, double dp[]) {
        if (k == 0) {
            set(i, j, k, 1, dp);
            return;
        }
        if (at(i, j, k, dp) >= 0) {
            return;
        }

        vector<vector<int>> neighbors = {
            {i + 1, j + 2},
            {i + 1, j - 2},
            {i - 1, j + 2},
            {i - 1, j - 2},
            {i + 2, j + 1},
            {i + 2, j - 1},
            {i - 2, j + 1},
            {i - 2, j - 1},
        };

        set(i, j, k, 0, dp);

        for(auto& point: neighbors) {
            if (is_valid(point)) {
                int x = point[0];
                int y = point[1];
                rec(x, y, k - 1, dp);
                double val = at(i, j, k, dp) + at(x, y, k - 1, dp);
                set(i, j, k, val, dp);
            }
        }

        set(i, j, k, at(i, j, k, dp) / 8, dp);
    }
};
