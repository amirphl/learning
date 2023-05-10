// https://leetcode.com/problems/find-the-most-competitive-subsequence/

#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(const vector<int> &a, const vector<int> &b) const
	{
		return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
	}
};

class Solution
{
      public:
	// TLE
	vector<int> mostCompetitive(vector<int> &nums, int k)
	{
		int n = nums.size();
		vector<int> res(k);
		for (int i = 0, u = 0; i < n && k > 0;) {
			int min_index = i;
			for (int j = i + 1; j <= n - k; j++) {
				if (nums[j] < nums[min_index]) {
					min_index = j;
				}
			}
			res[u] = nums[min_index];
			u++;
			k--;
			i = min_index + 1;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
