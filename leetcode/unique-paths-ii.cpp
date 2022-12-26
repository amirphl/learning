// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int64_t *curr = new int64_t[m];

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == n - 1 && j == m - 1) {
                    curr[j] = 1;
                } else {
                    curr[j] = (i + 1 < n ? curr[j] : 0) + (j + 1 < m ? curr[j + 1] : 0);
                }
            }
        }

        // TODO delete curr
        return curr[0];
    }
};
