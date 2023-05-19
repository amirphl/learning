// https://quera.org/contest/assignments/53487/problems/182487

#include "bits/stdc++.h"

using namespace std;


class Sol
{
      public:
	int64_t func2(char colors[], int nums[], int edges[][2], int n, int red)
	{
		int64_t res = 0;
		vector<vector<int>> adj(n, vector<int>());

		for (int i = 0; i < n - 1; i++) {
			int src = edges[i][0];
			int dest = edges[i][1];
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}

		int parent[n];
		bool vis[n];
		memset(vis, 0, sizeof(vis));

		queue<vector<int>> q;
		q.push({red, nums[red], -1});
		stack<int> s;

		while (!(q.empty())) {
			int idx = q.front()[0];
			int cost = q.front()[1];
			int par = q.front()[2];

			q.pop();

			parent[idx] = par;

			if (colors[idx] == 'R') {
				s.push(idx);
				res += cost;
				cost = 0;
			}

			for (auto &nei : adj[idx]) {
				if (nei == par) {
					continue;
				}
				q.push({nei, cost + nums[nei], idx});
			}
		}

		while (!(s.empty())) {
			int idx = s.top();
			s.pop();
			// cout << idx << " ===== \n";

			do {
				for (auto &nei : adj[idx]) {
					if (nei == parent[idx] || vis[nei]) {
						// cout << "    skip " << nei <<
						// endl;
						continue;
					}
					int64_t sum = 0;
					add(nei, adj, nums, parent, n, sum);
					res += sum;
					// cout << "    >> " << nei << " " <<
					// sum << endl;
				}

				vis[idx] = 1;
				idx = parent[idx];
			} while (parent[idx] != -1 && !vis[idx]);
		}

		return res;
	}

	void add(int root, vector<vector<int>> &adj, int nums[], int parent[],
		 int n, int64_t &sum)
	{
		int r = nums[root];
		for (auto &nei : adj[root]) {
			if (nei == parent[root]) {
				continue;
			}
			int64_t s = 0;
			add(nei, adj, nums, parent, n, s);
			if (s > 0) {
				r += s;
			}
		}

		if (r > 0) {
			sum = r;
		} else {
			sum = 0;
		}
	}

	int64_t func(char colors[], int nums[], int edges[][2], int n, int red)
	{
		vector<vector<int>> adj(n, vector<int>());

		for (int i = 0; i < n - 1; i++) {
			int src = edges[i][0];
			int dest = edges[i][1];
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}

		int node;
		int64_t res;
		rec2(red, colors, nums, -1, adj, node, res);
		return res;
	}

	void rec2(int root, char colors[], int nums[], int parent,
		  vector<vector<int>> &adj, int &node, int64_t &res)
	{
		int64_t s = nums[root];
		bool found_red = colors[root] == 'R';

		for (auto &nei : adj[root]) {
			if (nei == parent) {
				continue;
			}

			int u;
			int64_t c;
			rec2(nei, colors, nums, root, adj, u, c);

			if (u != -1) {
				found_red = 1;
				s += c;
			} else if (c > 0) {
				s += c;
			}
		}

		if (found_red) {
			node = root;
			res = s;
		} else {
			node = -1;

			if (s > 0) {
				res = s;
			} else {
				res = 0;
			}
		}
	}
};

int main()
{
	int n;
	int red;
	cin >> n;
	char colors[n];
	for (int i = 0; i < n; i++) {
		cin >> colors[i];
		if (colors[i] == 'R') {
			red = i;
		}
	}
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int edges[n - 1][2];
	for (int i = 0; i < n - 1; i++) {
		cin >> edges[i][0];
		cin >> edges[i][1];
		edges[i][0]--;
		edges[i][1]--;
	}

	Sol sol;
	// cout << " ---- " << endl;
	cout << sol.func(colors, nums, edges, n, red) << endl;

	return 0;
}

