// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	vector<vector<string>> displayTable(vector<vector<string>> &orders)
	{
		map<int, int> tables;
		map<string, int> foods;

		for (auto &row : orders) {
			tables[stoi(row[1])] = 1;
			foods[row[2]] = 1;
		}

		int n = tables.size();
		int m = foods.size();
		vector<vector<string>> res(n + 1, vector<string>(m + 1, "0"));
		int t;
		string f;
		int x, y;
		res[0][0] = "Table";

		int i = 1;
		for (auto it = tables.begin(); it != tables.end(); it++, i++) {
			res[i][0] = to_string(it->first);
			tables[it->first] = i;
		}

		i = 1;
		for (auto it = foods.begin(); it != foods.end(); it++, i++) {
			res[0][i] = it->first;
			foods[it->first] = i;
		}

		for (auto &row : orders) {
			t = stoi(row[1]);
			f = row[2];
			y = foods[f];
			x = tables[t];
			res[x][y] = to_string(stoi(res[x][y]) + 1);
		}

		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
