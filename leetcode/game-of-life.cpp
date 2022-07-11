// https://leetcode.com/problems/game-of-life/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n*m), memory: O(1)
    int get_alive_neighbors(int i, int j, vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int alive_neighbors = 0;
        vector<vector<int>> neighbors = {{i - 1, j - 1},
            {i - 1, j},
            {i - 1, j + 1},
            {i, j - 1},
            {i, j + 1},
            {i + 1, j - 1},
            {i + 1, j},
            {i + 1, j + 1}
        };
        for(auto& v: neighbors) {
            if (0 <= v[0] && v[0] <= n - 1 && 0 <= v[1] && v[1] <= m - 1 && board[v[0]][v[1]] % 2 == 1) {
                alive_neighbors++;
            }
        }

        return alive_neighbors;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int i = 0;
        while(i < n) {
            int j = 0;
            while(j < m) {
                int alive_neighbors = get_alive_neighbors(i, j, board);
                // if (i == 1 && j == 0) {
                //     cout << alive_neighbors << endl;
                // }
                if (board[i][j] == 1 && (alive_neighbors < 2 || 3 < alive_neighbors)) {
                    board[i][j] = 3;
                } else if (board[i][j] == 0 && alive_neighbors == 3) {
                    board[i][j] = 2;
                }
                j++;
            }
            i++;
        }
        i = 0;
        while(i < n) {
            int j = 0;
            while(j < m) {
                if (board[i][j] == 3) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
                j++;
            }
            i++;
        }
    }
};

int main() {
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution sol;
    sol.gameOfLife(board);
    for(auto& v: board) {
        for(auto& elem: v) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
