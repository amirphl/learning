// https://leetcode.com/problems/permutations-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	int n;
	vector<int> curr;
	vector<int> nums;
	vector<vector<int>> res;
	int freq[21];

	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());

		memset(freq, 0, sizeof(freq));
		for (auto &elem : nums) {
			freq[elem + 10]++;
		}

		this->n = nums.size();
		this->nums = nums;
		this->curr = vector<int>(n);

		rec(0);

		return res;
	}

	void rec(int idx)
	{
		if (idx == n) {
			res.push_back(curr);
			return;
		}

		for (int i = 0; i < 21; i++) {
			if (freq[i] > 0) {
				freq[i]--;
				curr[idx] = i - 10;
				rec(idx + 1);
				freq[i]++;
			}
		}
	}
};

int main()
{
	Solution sol;
	return 0;
}
