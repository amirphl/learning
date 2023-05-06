// https://leetcode.com/problems/shortest-bridge/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	uint64_t make_key(int x, int y)
	{
		uint64_t z = 0;
		z += x;
		z = z << 32;
		return z + y;
	}

	bool is_valid(int x, int y, int n, int m)
	{
		return 0 <= x && x < n && 0 <= y && y < m;
	}

	int shortestBridge(vector<vector<int>> &grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		int row = -1, col, x, y, lvl;
		uint64_t z;

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
		unordered_set<uint64_t> visited;
		q.push({row, col});
		q2.push({row, col, 0});
		visited.insert(make_key(row, col));

		while (!q.empty()) {
			row = q.front()[0];
			col = q.front()[1];
			q.pop();

			for (auto &d : dir) {
				x = row + d[0];
				y = col + d[1];
				z = make_key(x, y);

				if (is_valid(x, y, n, m) && grid[x][y] == 1 &&
				    visited.find(z) == visited.end()) {
					q.push({x, y});
					q2.push({x, y, 0});
					visited.insert(z);
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
				z = make_key(x, y);

				if (is_valid(x, y, n, m) &&
				    visited.find(z) == visited.end()) {
					if (grid[x][y] == 1) {
						return lvl;
					}

					q2.push({x, y, lvl + 1});
					visited.insert(z);
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
