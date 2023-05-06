// https://leetcode.com/problems/shortest-bridge/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	bool is_valid(int x, int y, int n, int m)
	{
		return 0 <= x && x < n && 0 <= y && y < m;
	}

	int shortestBridge(vector<vector<int>> &grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		int row = -1, col, x, y, lvl;

		for (int i = 0; i < n; i++) {
			bool found = false;

			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					row = i;
					col = j;
					found = true;
					break;
				}
			}
			if (found) {
				break;
			}
		}

		if (row == -1) {
			return INT_MAX;
		}

		vector<vector<int>> dir = {
		    {1, 0},
		    {0, 1},
		    {0, -1},
		    {-1, 0},
		};

		queue<vector<int>> q;
		queue<vector<int>> q2;
		bool visited[n][m];
		memset(visited, 0, sizeof(visited));

		q.push({row, col});
		q2.push({row, col, 0});
		visited[row][col] = 1;

		while (!q.empty()) {
			row = q.front()[0];
			col = q.front()[1];
			q.pop();

			for (auto &d : dir) {
				x = row + d[0];
				y = col + d[1];

				if (is_valid(x, y, n, m) && grid[x][y] == 1 &&
				    !visited[x][y]) {
					q.push({x, y});
					q2.push({x, y, 0});
					visited[x][y] = 1;
				}
			}
		}

		while (!q2.empty()) {
			row = q2.front()[0];
			col = q2.front()[1];
			lvl = q2.front()[2];
			q2.pop();

			for (auto &d : dir) {
				x = row + d[0];
				y = col + d[1];

				if (is_valid(x, y, n, m) && !visited[x][y]) {
					if (grid[x][y] == 1) {
						return lvl;
					}

					q2.push({x, y, lvl + 1});
					visited[x][y] = 1;
				}
			}
		}

		return INT_MAX;
	}
};

int main()
{
	Solution sol;
	return 0;
}
