// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	vector<vector<int>> adj;
	unordered_set<char> uni;

	vector<int> countSubTrees(int n, vector<vector<int>> &edges,
				  string labels)
	{
		this->adj = vector<vector<int>>(n);

		for (auto &e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}

		int par[n];
		queue<int> q;
		par[0] = -1;
		q.push(0);

		while (!(q.empty())) {
			int node = q.front();
			q.pop();
			for (auto &nei : adj[node]) {
				if (par[node] != nei) {
					par[nei] = node;
					q.push(nei);
				}
			}
		}

		int dp[n][26];
		memset(dp, 0, sizeof(dp));

		vector<int> res(n);
		int i = 0;

		this->uni = unordered_set<char>(labels.begin(), labels.end());
		rec(par[i], i, dp, labels);

		for (auto &ch : labels) {
			res[i] = dp[i][ch - 'a'];
			i++;
		}

		return res;
	}

	void rec(int par, int root, int dp[][26], string &labels)
	{
		for (auto &nei : adj[root]) {
			if (par == nei) {
				continue;
			}

			rec(root, nei, dp, labels);

			for (auto &ch : uni) {
				dp[root][ch - 'a'] += dp[nei][ch - 'a'];
			}
		}

		dp[root][labels[root] - 'a']++;
	}
};

int main()
{
	Solution sol;
	return 0;
}
