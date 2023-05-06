// https://leetcode.com/problems/permutations-ii/

#include <bits/stdc++.h>

using namespace std;

struct hashfunc {
	size_t operator()(vector<int> const &vec) const
	{
		size_t seed = vec.size();
		for (auto &i : vec) {
			seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};

class Solution
{
      public:
	int n;
	vector<int> curr;
	vector<int> nums;
	vector<vector<int>> res;
	unordered_set < vector<int>, hashfunc> visited;
	int delim = -100;

	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		this->n = nums.size();
		this->nums = nums;
		this->curr = vector<int>(n);
		rec(0);

		return res;
	}

	void rec(int idx)
	{
		if (idx == n) {
			if (visited.find(curr) == visited.end()) {
				res.push_back(curr);
				visited.insert(curr);
			}

			return;
		}

		int backup;

		for (int i = 0; i < n; i++) {
			if (nums[i] != delim) {
				backup = nums[i];
				nums[i] = delim;
				curr[idx] = backup;
				rec(idx + 1);
				nums[i] = backup;
			}
		}
	}
};

int main()
{
	Solution sol;
	return 0;
}
