// https://leetcode.com/problems/find-the-most-competitive-subsequence/

#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(const vector<int> &a, const vector<int> &b) const
	{
		return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
	}
};

class Solution
{
      public:
	vector<int> mostCompetitive(vector<int> &nums, int k)
	{
		int n = nums.size();
		vector<int> res(k);
		priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
		for (int i = 0; i <= n - k; i++) {
			pq.push({nums[i], i});
		}

		int i = 0;
		int j = n - k + 1;
		while (i < k) {
			res[i] = pq.top()[0];
			int pos = pq.top()[1];
			pq.pop();
			i++;
			while (!(pq.empty()) && pq.top()[1] < pos) {
				pq.pop();
			}
			if (j < n)
				pq.push({nums[j], j});
			j++;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
