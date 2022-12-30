// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    queue<vector<int>> q;
                    q.push({i, j});
                    grid[i][j] = '2';

                    while(!q.empty()) {
                        int x = q.front()[0];
                        int y = q.front()[1];
                        q.pop();

                        if (is_valid(x - 1, y, n, m) && grid[x - 1][y] == '1') {
                            grid[x - 1][y] = '2';
                            q.push({x - 1, y});
                        }
                        if (is_valid(x + 1, y, n, m) && grid[x + 1][y] == '1') {
                            grid[x + 1][y] = '2';
                            q.push({x + 1, y});
                        }
                        if (is_valid(x, y - 1, n, m) && grid[x][y - 1] == '1') {
                            grid[x][y - 1] = '2';
                            q.push({x, y - 1});
                        }
                        if (is_valid(x, y + 1, n, m) && grid[x][y + 1] == '1') {
                            grid[x][y + 1] = '2';
                            q.push({x, y + 1});
                        }
                    }
                }
            }
        }

        return count;
    }

    bool is_valid(int x, int y, int n, int m) {
        return x >=0 && x < n && y >= 0 && y < m;
    }
};
