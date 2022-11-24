// https://leetcode.com/problems/word-search/

class Solution {
public:
    int dp[6][6][15] = {0};
    int n, m, p;

    bool exist(vector<vector<char>>& board, string& word) {
        n = board.size();
        m = board[0].size();
        p = word.length();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (!(0 <= i && i < n && 0 <= j && j < m) || p <= k || board[i][j] != word[k]) {
            return false;
        }

        if (word.length() == k + 1) {
            return true;
        }

        char backup = board[i][j];
        board[i][j] = '+';

        if (dfs(board, word, i - 1, j, k + 1)
                || dfs(board, word, i + 1, j, k + 1)
                || dfs(board, word, i, j - 1, k + 1)
                || dfs(board, word, i, j + 1, k + 1)) {
            return true;
        }

        board[i][j] = backup;
        return false;
    }

    // doesn't handle <The same letter cell may not be used more than once.>
    int rec(vector<vector<char>>& board, string& word, int i, int j, int k) {
        int n = board.size();
        int m = board[0].size();
        int p = word.length();

        if (!(0 <= i && i < n && 0 <= j && j < m) || p <= k) {
            // cout << i << " __ " << j << " __ " << k << "\n";
            return -1;
        }

        if (dp[i][j][k] != 0) {
            // cout << i << " ++ " << j << " ++ " << k << "\n";
            return dp[i][j][k];
        }

        if (board[i][j] != word[k]) {
            // cout << i << " == " << j << " == " << k << "\n";
            return dp[i][j][k] = -1;
        }

        if (word.length() == k + 1) {
            // cout << i << " ** " << j << " ** " << k << "\n";
            return dp[i][j][k] = 1;
        }

        if (rec(board, word, i - 1, j, k + 1) == 1
                || rec(board, word, i + 1, j, k + 1) == 1
                || rec(board, word, i, j - 1, k + 1) == 1
                || rec(board, word, i, j + 1, k + 1) == 1) {
            // cout << i << " || " << j << " || " << k << "\n";
            return dp[i][j][k] = 1;
        }

        // cout << i << " .. " << j << " .. " << k << "\n";
        return dp[i][j][k] = -1;
    }
};
