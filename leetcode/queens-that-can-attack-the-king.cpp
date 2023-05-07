// https://leetcode.com/problems/queens-that-can-attack-the-king/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	bool q[8][8];

	bool theres_queen(int i, int j)
	{
		return q[i][j];
	}

	vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
						vector<int> &king)
	{
		memset(q, 0, sizeof(q));

		for (auto &pos : queens) {
			q[pos[0]][pos[1]] = 1;
		}

		vector<vector<int>> res;

		for (int i = king[0] - 1; i >= 0; i--) {
			if (theres_queen(i, king[1])) {
				res.push_back({i, king[1]});
				break;
			}
		}
		for (int i = king[0] + 1; i < 8; i++) {
			if (theres_queen(i, king[1])) {
				res.push_back({i, king[1]});
				break;
			}
		}
		for (int i = king[1] - 1; i >= 0; i--) {
			if (theres_queen(king[0], i)) {
				res.push_back({king[0], i});
				break;
			}
		}
		for (int i = king[1] + 1; i < 8; i++) {
			if (theres_queen(king[0], i)) {
				res.push_back({king[0], i});
				break;
			}
		}
		for (int i = king[0] + 1, j = king[1] + 1; i < 8 && j < 8;
		     i++, j++) {
			if (theres_queen(i, j)) {
				res.push_back({i, j});
				break;
			}
		}
		for (int i = king[0] - 1, j = king[1] - 1; i >= 0 && j >= 0;
		     i--, j--) {
			if (theres_queen(i, j)) {
				res.push_back({i, j});
				break;
			}
		}
		for (int i = king[0] - 1, j = king[1] + 1; i >= 0 && j < 8;
		     i--, j++) {
			if (theres_queen(i, j)) {
				res.push_back({i, j});
				break;
			}
		}
		for (int i = king[0] + 1, j = king[1] - 1; i < 8 && j >= 0;
		     i++, j--) {
			if (theres_queen(i, j)) {
				res.push_back({i, j});
				break;
			}
		}

		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
